/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/01 16:43:50 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	cub3d_maker(int clr)
{
	int	i;
	int	j;

	i = 0;
	//camera_plane();
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
