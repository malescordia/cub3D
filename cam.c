/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/14 18:50:19 by cbouvet          ###   ########.fr       */
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

void	data_parser(char **content, int lines)
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
