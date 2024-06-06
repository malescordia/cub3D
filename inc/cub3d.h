/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:02:09 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/06 18:00:14 by cbouvet          ###   ########.fr       */
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
# define CELL_SIZE 		100
// 3D display
# define HEIGHT			800
# define WIDTH			800
# define FOV			0.66
// Speed
# define MV_SPEED		0.05
# define ROT_DEG		8
// Maths
# define PI 			3.14159265358979323846

// -STRUCTS-
// Texture struct
typedef struct s_tex
{
	char			*name;
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				bit_pix;
	int				endian;
	int				line_len;
	int				pixel[2];
}	t_tex;
// Map struct
typedef struct s_map
{
	char	**cmap;
	int		height;
	int		width;
	int		f_clr;
	int		c_clr;
	t_tex	ntx;
	t_tex	etx;
	t_tex	wtx;
	t_tex	stx;
}	t_map;
// Player struct
typedef struct s_player
{
	int		side;
	int		wall[2];
	double	dir;
	double	dir_arr[2];
	double	pos[2];
	double	ray[2];
	double	delta[2];
	double	plane[2];
	double	side_dist[2];
	double	fov_dir;
}	t_player;
// Display struct
typedef struct s_disp
{
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
	void		*mlx;
	t_disp		disp_2d;
	t_disp		disp_3d;
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
// Data parser
void	check_dup(char **txt, int lines);
char	*tx_error(char **txt, int i);
int		clr_to_hex(char **txt, int i);
int		check_rgb(char **rgb);
char	*hex_str(int res);
// Data parser utils
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
void	init_display(t_disp *disp, int code, char *name);
void	init_img(t_disp *disp);
void	my_pixel_put(t_disp *disp, int x, int y, int clr);
void	init_hooks(t_disp *disp);
// 2D Display
void	cub2d_maker(char **map);
void	draw_cell(t_disp *disp, int x, int y, int clr);
void	put_player(t_disp *disp, double x, double y);
void	draw_line(t_disp *disp, double x, double y);
void	bound_checker(double dest_x, double dest_y);
// 3D Display

// Hooks & Events
int		key_press(int code);
int		key_release(int code);
int		hooks_handler(void);
void	hooks_mvt(double x_dest, double y_dest);
void	hooks_rot(void);
// Clean & exit
void	clean_exit(char *err_msg, int err_code);
void	free_map(t_map *map);
void	free_display(t_disp *disp);
void	free_imatrix(int **matrix, int indexes);
void	free_cmatrix(char **matrix);
// Testing shite
void	print_tests(void);
void	draw_camera_plane(double x, double y);
void	camera_plane(t_player *player);
double	cast_ray(t_player *player);
void	draw_wall(int x, int start, int end);
void	initialize_plane(void);
// Gui
void	draw(void);
void	draw_image(int x, int start, int end);
t_tex	get_texture(void);
void	dda(void);
void	before_dda(void);
void	load_all_textures(void *mlx, t_tex textures[4]);
void	load_texture(void *mlx, t_tex *tex, char *path);
int		init_textures(t_map *map);
// TEST RAYCASTER
void	cub3d_maker(t_player *player);
void	set_variables(t_player *player, double cam);
int		step_incr(t_player *player, int axis);
double	raycaster(t_player *player, int step_x, int step_y);
void	visual_render(t_player *player, int i, int wall_height, double	perp_dist);
void	map_dimensions(char **map);
void	set_texture(t_tex *tex, char **txt, int i);
int draw_texture(t_player *player, t_tex *tex, int wall_height, double	perp_dist);

#endif
