/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/03 17:07:17 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	cub3d_maker(int clr)
{
	int	i;
	int	j;

	i = 0;
	// camera_plane();
	var()->player.plane = var()->player.dir - 90;
	if (var()->player.plane < 0)
		var()->player.plane = 360 - (var()->player.plane * (-1));
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			my_pixel_put(&var()->disp_3d, j++, i, clr);
		i++;
	}
}

void	camera_plane(t_player *player)
{
	int	i;
	double	cam;

	i = 0;
	while (i < var()->disp_3d.width)
	{
		cam = 2 * i / (double)var()->disp_3d.width -1;
		player->ray[0] = cos(player->dir * PI / 180) + \
		cos(player->plane * PI / 180) * cam;
		player->ray[1] = sin(player->dir * PI / 180) + \
		sin(player->plane * PI / 180) * cam;
		cast_ray(player);
		i++;
	}
	mlx_put_image_to_window(var()->mlx, var()->disp_3d.win, \
	var()->disp_3d.img, 0, 0);
}

void	cast_ray(t_player *player)
{
}

void	draw_camera_plane(double x, double y)
{
	double	i;
	double	j;

	i = y;
	j = x;
	while (var()->map.cmap[(int)(y / CELL_SIZE)][(int)(x / CELL_SIZE)] != '1')
	{
		x += sin(var()->player.plane * PI / 180);
		y += -cos(var()->player.plane * PI / 180);
		my_pixel_put(&var()->disp_2d, x, y, 0x00FF00);
	}
	while (var()->map.cmap[(int)(i / CELL_SIZE)][(int)(j / CELL_SIZE)] != '1')
	{
		j -= sin(var()->player.plane * PI / 180);
		i -= -cos(var()->player.plane * PI / 180);
		my_pixel_put(&var()->disp_2d, j, i, 0x00FF00);
	}
}
