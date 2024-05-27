/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:02:09 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/27 16:51:48 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// -LIBRARIES-
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

// -MACROS-
// Param err - 1
# define PARAM_NB		"Incorrect number of parameters"
# define EMPTY_PARAM	"Empty parameter"
# define WRONG_EXT		"Wrong file extension"
// File err - 2
# define WRONG_DATA		"Incorrect file data"
# define MALLOC_ERR		"Memory allocation failed"
# define DUP_ERR		"Duplicate data in file"
# define BAD_MAP		"Invalid map"
// Display err - 3
# define WIN_ERR		"Display or window failure"
# define IMG_ERR		"Image rendering failure"
// 2D display
# define SCREENWIDTH 800
# define SCREENHEIGHT 800
# define CELL_SIZE 100
// Speed
# define MV_SPEED	0.05
# define ROT_SPEED	0.03

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
// Player struct
typedef struct s_player
{
	double	pos[2]; // <- Player position on map
	double	dir[2]; // <- direction player is facing
	double	plane[2]; // <- camera plane vector - always perpendicular to the direction vector
	double	fov; // <- field of view
}	t_player;
// Display struct
typedef struct s_disp
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bit_pix;
	int		endian;
	int		width;
	int		height;

}	t_disp;

// All-encompassing struct
typedef struct s_var
{
	t_map		map;
	t_player	player;
	t_disp		disp;
	bool		w_key;
	bool		a_key;
	bool		s_key;
	bool		d_key;
	bool		left;
	bool		right;
}	t_var;

// -FUNCTIONS-
// Base
t_var	*var(void);
// Parser
void	parser(char **av);
char	**store_mapfile(int fd);
int		data_parser(char **txt);
void	map_parser(char **txt, int i);
void	create_imap(t_map *map);
// Data parser
void	check_dup(char **txt, int lines);
char	*tx_error(char **txt, int i);
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
// Player
void	init_player(char **map);
void	define_facing(t_player *player, char facing);
// Display
void	init_display(t_disp *disp);
void	init_img(t_disp *disp);
void	cube_mker(char **map);
// 2D
void	draw_cell(t_disp *disp, int x, int y, int clr);
void	put_player(t_disp *disp, double x, double y);
void	my_pixel_put(t_disp *disp, int x, int y, int clr);
// Hooks & Events
int		key_press(int code);
int		hooks_handler(void);
void	bound_checker(int index, int axis, double target_pos);
// Clean & exit
void	clean_exit(char *err_msg, int err_code);
void	free_map(t_map *map);
void	free_display(t_disp *disp);
void	free_imatrix(int **matrix, int indexes);
void	free_cmatrix(char **matrix);
// Testing shite
void	print_tests(void);

#endif
