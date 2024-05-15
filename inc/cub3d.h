/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:02:09 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/15 19:14:39 by cbouvet          ###   ########.fr       */
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
# define PARAM_NB		"Incorrect number of parameters\n"
# define EMPTY_PARAM	"Empty parameter\n"
# define WRONG_DATA		"Incorrect file data\n"
# define MALLOC_ERR		"Memory allocation failed\n"
# define DUP_ERR		"Duplicate data in file\n"

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
	char 	**ceiling_split; // name is big only to make clear what it contains, you can make it small ofc :)
	char 	**floor_split; // name is big only to make clear what it contains, you can make it small ofc :)
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
// Data parser
int		data_parser(char **content, int lines);
char	*tx_err(char **content, int i);
int		clr_to_int(char *code);
int		check_rgb(t_map *map);
// TO DO - CONVERT TO HEXA
// Data parser utils
int		get_line_nb(int fd);
void	check_dup(char **content, int lines);
int		tx_complete(t_map *map);
int		is_separator(char *buff);
int		skip_sep(char *str, int i);
int		is_map(char *content);
// Map parser
void	map_parser(char **content, int i);
int		check_characters(char **map);
int		check_line(char **map);
int		check_column(char **map);
int		kinda_floodfill(char **map);
int 	check_player(char **map);
// Map parser utils
int		map_len(char **map);
int		mapline_strlen(char *str);
int		check_borders(int i);
int		check_up(int i, int j);
int		check_down(int i, int j);
// Display
void	display_win(void);
// Hooks & Events
int key_press(int code, t_var *data);
// Clean & exit
void	clean_exit(char *err_msg, int err_code);
void	free_matrix(char **matrix);

#endif
