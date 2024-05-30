/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:02:09 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/30 14:58:28 by cbouvet          ###   ########.fr       */
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
// Errors
# define PARAM_NB		"Incorrect number of parameters"
# define EMPTY_PARAM	"Empty parameter"
# define WRONG_EXT		"Wrong file extension"
# define WRONG_DATA		"Incorrect file data"
# define MALLOC_ERR		"Memory allocation failed"
# define DUP_ERR		"Duplicate data in file"
# define BAD_MAP		"Invalid map"
# define WIN_ERR		"Display or window failure"
# define IMG_ERR		"Image rendering failure"
// 2D display
# define CELL_SIZE 100
// Speed
# define MV_SPEED	0.05
# define ROT_DEG	1.5
// Maths
# define PI 		3.14159265358979323846

// -STRUCTS-
// Texture struct
typedef struct s_tex
{
	void			*img;
	int				height;
	int				width;
	unsigned int	*addr;
	int				bit_pix;
	int				endian;
	int				line_len;
}	t_tex;
// Map struct
typedef struct s_map
{
	char	*ntx;
	char	*etx;
	char	*wtx;
	char	*stx;
	char	*fhex;
	char	*chex;
	t_tex		n_wall;
	t_tex		e_wall;
	t_tex		w_wall;
	t_tex		s_wall;
	t_tex		render;
	char	**cmap;
	int		**imap;
}	t_map;
// Player struct
typedef struct s_player
{
	double	pos[2];
	double	dir;
	double	plane[2];
	double	fov;
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
// 2D Display
void	draw_cell(t_disp *disp, int x, int y, int clr);
void	put_player(t_disp *disp, double x, double y);
void	draw_line(t_disp *disp, double x, double y);
void	my_pixel_put(t_disp *disp, int x, int y, int clr);
// Hooks & Events
int		key_press(int code);
int		hooks_handler(void);
void	hooks_mvt(double x_dest, double y_dest);
void	hooks_rot(void);
void	bound_checker(double dest_x, double dest_y);
// Clean & exit
void	clean_exit(char *err_msg, int err_code);
void	free_map(t_map *map);
void	free_display(t_disp *disp);
void	free_imatrix(int **matrix, int indexes);
void	free_cmatrix(char **matrix);
// Testing shite
void	print_tests(void);
void	make_all_false(void);
int		init_textures(t_map *map);
int		key_release(int code);

#endif
