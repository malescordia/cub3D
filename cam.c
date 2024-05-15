/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/15 18:34:12 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	get_line_nb(int fd)
{
	int		lines;

	lines = 0;
	while (!EOF)
	{
		get_next_line(fd);
		lines++;
	}
	return (lines);
}

void	check_dup(char **content, int lines)
{
	int	i;
	int j;

	i = 0;
	while (content[i] && i < lines -1)
	{
		j = i +1;
		while (content[j])
		{
			if ((!ft_strncmp(content[i], content[j], ft_strlen(content[i])) \
			&& !is_map(content[i])) \
			|| (!ft_strncmp(&content[i][3], &content[j][3], ft_strlen(&content[i][3])) \
			&& !is_map(&content[i])))
			{
				free_matrix(content);
				clean_exit(DUP_ERR, 2);
			}
			j++;
		}
		i++;
	}
}

int	data_parser(char **content, int lines)
{
	int	i;

	i = 0;
	check_dup(content, lines);
	while (content[i] && !tx_complete(var()->map))
	{
		if (!ft_strnmp(content[i], "NO ", 3) && !var()->map->ntx)
			var()->map->ntx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "EA ", 3) && !var()->map->etx)
			var()->map->etx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "WE ", 3) && !var()->map->wtx)
			var()->map->wtx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "SO ", 3) && !var()->map->stx)
			var()->map->stx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "F ", i) && !var()->map->ftx)
			var()->map->ftx = clr_to_hex(content);
		else if (!ft_strncmp(content[i], "C ", i) && !var()->map->ctx)
			var()->map->ctx = clr_to_hex(content);
		else if (!is_separator(content[i]))
			clean_exit(WRONG_DATA, 2);
		i++;
	}
	return (i);
}


int	tx_complete(t_map *map)
{
	if (!map->ntx || !map->etx || !map->wtx || !map->stx || !map->ftx || !map->ctx)
		return (0);
	return (1);
}

char	*tx_err(char **content, int i)
{
	int	tx_fd;

	tx_fd = open(&content[i][3], O_WRONLY);
	if (tx_fd < 0)
	{
		free_matrix(content);
		clean_exit(strerror(errno), 2);
	}
	close(tx_fd);
	return (ft_strdup(&content[3]));
}

int	is_separator(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] < 9 || content[i] > 13 || content != " ")
			return (0);
		i++;
	}
	return (1);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix)
	{
		while(matrix[i])
			free(matrix[i++]);
		free(matrix);
	}
}

int	is_map(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] != '0' && content[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	map_parser(char **content, int i)
{
	int		j;
	int		start;

	while (is_separator(content[i]))
		i++;
	start = i;
	while (!is_separator(content[i]))
		i++;
	var()->map->cmap = ft_calloc(i-start+1, sizeof(char *));
	j = 0;
	while (start < i)
		var()->map->cmap[j++] = ft_strdup(content[start++]);
	check_characters(var()->map->cmap);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:02:09 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/15 18:27:45 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

// -LIBRARIES-
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

// -MACROS-
// Errorrs
# define PARAM_NB		"Incorrect number of parameters."
# define EMPTY_PARAM	"Empty parameter."
# define WRONG_DATA		"Incorrect file data."
# define MALLOC_ERR		"Memory allocation failed"
# define DUP_ERR		"Duplicate data in file"

// -STRUCTS-
// Map struct
typedef struct s_map
{
	char	**map;
	char	*ntx;
	char	*etx;
	char	*wtx;
	char	*stx;
	char	*ftx;
	char	*ctx;
	char	**cmap;
	int		**imap;
}	t_map;
// All-encompassing struct
typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_var;

// -FUNCTIONS-
// Base
t_var	*var(void);
// Parser
void	parser(char **av);
int		tx_complete(t_map *map);
char	*tx_err(char *buff, int fd);
int		is_separator(char *buff);
// Data parser
int		get_line_nb(int fd);
void	check_dup(char **content, int lines);
int		data_parser(char **content, int lines);
int		tx_complete(t_map *map);
char	*tx_err(char *buff, int fd);
int		is_separator(char *buff);
// Map parser
void	map_parser(char **content, int i);
int		map_len(char **map);
int		mapline_strlen(char *str);
int		check_borders(int i);
int		check_column(void);
int		check_up(int i, int j);
int		check_down(int i, int j);
int		check_line(void);
int		check_character(void);
int		kinda_floodfill(void);
int		check_player(void);
// Texture parser
int		get_newsfc(char *line);
int		clr_to_int(char *code);
// Display
void	display_win(void);
// Clean & exit
void	clean_exit(char *err_msg, int err_code);

#endif
