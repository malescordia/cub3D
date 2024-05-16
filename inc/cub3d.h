/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:02:09 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/16 20:45:19 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
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
# define PARAM_NB		"Incorrect number of parameters"
# define EMPTY_PARAM	"Empty parameter"
# define WRONG_DATA		"Incorrect file data"
# define MALLOC_ERR		"Memory allocation failed"
# define DUP_ERR		"Duplicate data in file"
# define BAD_MAP		"Invalid map"
# define WIN_ERR		"Display or window failure"

// -STRUCTS-
// Map struct
typedef struct s_map
{
	char	*ntx;
	char	*etx;
	char	*wtx;
	char	*stx;
	char	*fhex;
	char	*chex;
	char	**cmap;
	int		**imap;
}	t_map;
// All-encompassing struct
typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_map	map;
}	t_var;

// -FUNCTIONS-
// Base
t_var	*var(void);
// Parser
void	parser(char **av);
int		data_parser(char **txt, int lines);
void	map_parser(char **txt, int i);
// Data parser
void	check_dup(char **txt, int lines);
char	*tx_err(char **txt, int i);
char	*clr_to_hex(char **txt, int i);
int		check_rgb(char **rgb);
char	*hex_str(int res);
// Data parser utils
int		get_line_nb(char *filename);
int		tx_complete(t_map *map);
int		skip_sep(char *str, int i);
int		is_separator(char *buff);
int		is_map(char *txt);
// Map parser
int		check_characters(char **map);
int		check_line(char **map);
int		check_column(char **map);
int		kinda_floodfill(char **map);
int		check_player(char **map);
// Map parser utils
int		get_2d_len(char **map);
int		strlen_until_newline(char *str);
int		check_borders(char **map, int i);
int		check_up(char **map, int i, int j);
int		check_down(char **map, int i, int j);
// Display
int		display_win(void);
// Hooks & Events
int		key_press(int code, t_var *data);
// Clean & exit
void	clean_exit(char *err_msg, int err_code);
void	free_map(t_map *map);
void	free_matrix(char **matrix);

#endif
