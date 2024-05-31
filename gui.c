/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/31 18:59:12 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

///////////////////////////////////////////
//               TEXTURES                //
///////////////////////////////////////////

// int	init_textures(t_map *map)
// {
// 	map->n_wall.img = mlx_xpm_file_to_image(var()->disp.mlx, map->ntx, \
// 		&map->n_wall.width, &map->n_wall.height);
// 	map->e_wall.img = mlx_xpm_file_to_image(var()->disp.mlx, map->etx, \
// 		&map->e_wall.width, &map->e_wall.height);
// 	map->w_wall.img = mlx_xpm_file_to_image(var()->disp.mlx, map->wtx, \
// 		&map->w_wall.width, &map->w_wall.height);
// 	map->s_wall.img = mlx_xpm_file_to_image(var()->disp.mlx, map->stx, \
// 		&map->s_wall.width, &map->s_wall.height);
// 	map->render.img = mlx_new_image(var()->disp.mlx, \
// 		var()->disp.width, var()->disp.height);
// 	if (!map->n_wall.img || !map->e_wall.img || !map->w_wall.img || \
// 		!map->s_wall.img || !map->render.img)
// 		clean_exit(IMG_ERR, 3);
// 	map->render.addr = (unsigned int *)mlx_get_data_addr(map->render.img, \
// 		&map->render.bit_pix, &map->render.line_len, &map->render.endian);
// 	map->n_wall.addr = (unsigned int *)mlx_get_data_addr(map->n_wall.img, \
// 		&map->n_wall.bit_pix, &map->n_wall.line_len, &map->n_wall.endian);
// 	map->e_wall.addr = (unsigned int *)mlx_get_data_addr(map->e_wall.img, \
// 		&map->e_wall.bit_pix, &map->e_wall.line_len, &map->e_wall.endian);
// 	map->w_wall.addr = (unsigned int *)mlx_get_data_addr(map->w_wall.img, \
// 		&map->w_wall.bit_pix, &map->w_wall.line_len, &map->w_wall.endian);
// 	map->s_wall.addr = (unsigned int *)mlx_get_data_addr(map->s_wall.img, \
// 		&map->s_wall.bit_pix, &map->s_wall.line_len, &map->s_wall.endian);
// 	return (0);
// }

// void load_texture(void *mlx, t_tex *tex, char *path)
// {
// 	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
// 	if (!tex->img)
// 		clean_exit(IMG_ERR, 3);
// 	tex->addr = (unsigned int *)mlx_get_data_addr(tex->img, \
// 		&tex->bit_pix, &tex->line_len, &tex->endian);
// }

// void load_all_textures(void *mlx, t_tex textures[4])
// {
// 	load_texture(mlx, &textures[0], "textures/blue.xpm");
// 	load_texture(mlx, &textures[1], "textures/grey.xpm");
// 	load_texture(mlx, &textures[2], "textures/yellow.xpm");
// 	load_texture(mlx, &textures[3], "textures/red.xpm");
// }

///////////////////////////////////////////
//             DDA                       //
///////////////////////////////////////////

// typedef struct s_map
// {
// 	char	*ntx;
// 	char	*etx;
// 	char	*wtx;
// 	char	*stx;
// 	char	*fhex;
// 	char	*chex;
// 	t_tex	n_wall;
// 	t_tex	e_wall;
// 	t_tex	w_wall;
// 	t_tex	s_wall;
// 	t_tex	render;
// 	char	**cmap;
// 	int		**imap;
// }	t_map;

// typedef struct s_player
// {
// 	double	pos[2];
// 	double	dir;
// 	double	plane[2];
// 	double	fov;
// 	double	fov_dir;
// }	t_player;

// typedef struct s_var
// {
// 	t_map		map;
// 	t_player	player;
// 	void		*mlx;
// 	t_disp		disp_2d;
// 	t_disp		disp_3d;
// 	bool		w_key;
// 	bool		a_key;
// 	bool		s_key;
// 	bool		d_key;
// 	bool		left;
// 	bool		right;
	
// 	int collision;
// 	int side;
	
// 	int map_x;
// 	int map_y;
	
// 	int step_x;
// 	int step_y;
	
// 	double ray_dir_x;
// 	double ray_dir_y;

// 	double s_dist_x;
// 	double s_dist_y;
	
// 	double delta_dist_x;
// 	double delta_dist_y;
// 	double perp_wall_dist;
// }	t_var;

// t_var	*var(void)
// {
// 	static t_var	var;

// 	return (&var);
// }

// void	before_dda(void)
// {
// 	var()->map_x = (int)var()->player.pos[0];
// 	var()->map_y = (int)var()->player.pos[1];
// 	var()->delta_dist_x = fabs(1 / var()->ray_dir_x);
// 	var()->delta_dist_y = fabs(1 / var()->ray_dir_y);
// 	if(var()->ray_dir_x < 0)
// 	{
// 		var()->step_x = -1;
// 		var()->s_dist_x = (var()->player.pos[0] - var()->map_x) * var()->delta_dist_x;
// 	}
// 	else
// 	{
// 		var()->step_x = 1;
// 		var()->s_dist_x = (var()->map_x + 1.0 - var()->player.pos[0]) * var()->delta_dist_x;
// 	}
// 	if(var()->ray_dir_y < 0)
// 	{
// 		var()->step_y = -1;
// 		var()->s_dist_y = (var()->player.pos[1] - var()->map_y) * var()->delta_dist_y;
// 	}
// 	else
// 	{
// 		var()->step_y = 1;
// 		var()->s_dist_y = (var()->map_y + 1.0 - var()->player.pos[1]) * var()->delta_dist_y;
// 	}
// }

// void	dda(void)
// {
// 	var()->collision = 0;
// 	while(var()->collision == 0)
// 	{
// 		if(var()->s_dist_x < var()->s_dist_y)
// 		{
// 			var()->s_dist_x += var()->delta_dist_x;
// 			var()->map_x += var()->step_x;
// 			var()->side = 0;
// 		}
// 		else
// 		{
// 			var()->s_dist_y += var()->delta_dist_y;
// 			var()->map_y += var()->step_y;
// 			var()->side = 1;
// 		}
// 		if(var()->map.imap[var()->map_x][var()->map_y] > 0)
// 			var()->collision = 1;
// 	}
// 	if(var()->side == 0)
// 		var()->perp_wall_dist = (var()->s_dist_x - var()->delta_dist_x);
// 	else
// 		var()->perp_wall_dist = (var()->s_dist_y - var()->delta_dist_y);
// }