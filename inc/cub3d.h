/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:02:09 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/15 18:07:36 by gude-cas         ###   ########.fr       */
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
# define PARAM_NB		"Error\nIncorrect number of parameters\n"
# define EMPTY_PARAM	"Error\nEmpty parameter\n"
# define WRONG_DATA		"Error\nIncorrect file data\n"
# define MALLOC_ERR		"Error\nMemory allocation failed\n"
# define DUP_ERR		"Error\nDuplicate data in file\n"

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
int		tx_complete(t_map *map);
char	*tx_err(char *buff, int fd);
int		is_separator(char *buff);
// Data parser
int		get_line_nb(int fd);
void	check_dup(char **content, int lines);
void	data_parser(char **content, int lines);
int		tx_complete(t_map *map);
char	*tx_err(char *buff, int fd);
int		is_separator(char *buff);
// Map parser
void	map_parser(int fd);
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
