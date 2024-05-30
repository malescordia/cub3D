/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/30 16:01:28 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	init_textures(t_map *map)
{
	map->n_wall.img = mlx_xpm_file_to_image(var()->disp.mlx, map->ntx, \
		&map->n_wall.width, &map->n_wall.height);
	map->e_wall.img = mlx_xpm_file_to_image(var()->disp.mlx, map->etx, \
		&map->e_wall.width, &map->e_wall.height);
	map->w_wall.img = mlx_xpm_file_to_image(var()->disp.mlx, map->wtx, \
		&map->w_wall.width, &map->w_wall.height);
	map->s_wall.img = mlx_xpm_file_to_image(var()->disp.mlx, map->stx, \
		&map->s_wall.width, &map->s_wall.height);
	map->render.img = mlx_new_image(var()->disp.mlx, \
		var()->disp.width, var()->disp.height);
	if (!map->n_wall.img || !map->e_wall.img || !map->w_wall.img || \
		!map->s_wall.img || !map->render.img)
		clean_exit(IMG_ERR, 3);
	map->render.addr = (unsigned int *)mlx_get_data_addr(map->render.img, \
		&map->render.bit_pix, &map->render.line_len, &map->render.endian);
	map->n_wall.addr = (unsigned int *)mlx_get_data_addr(map->n_wall.img, \
		&map->n_wall.bit_pix, &map->n_wall.line_len, &map->n_wall.endian);
	map->e_wall.addr = (unsigned int *)mlx_get_data_addr(map->e_wall.img, \
		&map->e_wall.bit_pix, &map->e_wall.line_len, &map->e_wall.endian);
	map->w_wall.addr = (unsigned int *)mlx_get_data_addr(map->w_wall.img, \
		&map->w_wall.bit_pix, &map->w_wall.line_len, &map->w_wall.endian);
	map->s_wall.addr = (unsigned int *)mlx_get_data_addr(map->s_wall.img, \
		&map->s_wall.bit_pix, &map->s_wall.line_len, &map->s_wall.endian);
	return (0);
}

// void *texture_maker(t_tex *tex)
// {
// 	tex = mlx_xpm_file_to_image(var()->disp.mlx, var()->map.ntx,
//		tex->width, tex->height)
// 	if (!tex)
// 		clean_exit(IMG_ERR, 3);
// }

// void init_textures(void)
// {
// 	var()->map.ntx.img =  texture_maker(&var()->map.ntx);
// 	var()->map.etx.img =  texture_maker(&var()->map.etx);
// 	var()->map.wtx.img =  texture_maker(&var()->map.wtx);
// 	var()->map.stx.img =  texture_maker(&var()->map.stx);
// }
