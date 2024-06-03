/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/03 20:11:54 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

/* void	cub3d_maker(int clr)
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
} */

void	cub3d_maker(t_player *player)
{
	int		i;
	int		wall_height;
	double	cam;
	double	wall_dist;
	double	ray_angle;

	i = 0;
	while (i < var()->disp_3d.width)
	{
		cam = 2 * i / (double)WIDTH -1;
		ray_angle = player->dir + player->plane * cam;
		player->ray[0] = cos(ray_angle * PI / 180);
		player->ray[1] = sin(ray_angle * PI / 180);
		set_variables();
		wall_dist = cast_ray(player);
		if (wall_dist == -1)
		{
			i++;
			continue;
		}
		wall_height = (int)(HEIGHT / wall_dist);
		draw_wall(i, wall_height);
		i++;
	}
	mlx_put_image_to_window(var()->mlx, var()->disp_3d.win, \
	var()->disp_3d.img, 0, 0);
}

double	cast_ray(t_player *player)
{
	double	pos[2];
	double	delta[2];

	pos[0] = player->pos[0];
	pos[1] = player->pos[1];
	while (1)
	{
		pos[0] += player->ray[0];
		pos[1] += player->ray[1];
		if (pos[1] < 0 || pos[1] > get_2d_len(var()->map.cmap) || \
		pos[0] < 0 || pos[0] > ft_strlen(var()->map.cmap[(int)pos[1]]))
			break ;
		if (var()->map.cmap[(int)pos[1]][(int)pos[0]] == '1')
		{
			delta[0] = pos[0] - player->pos[0];
			delta[1] = pos[1] - player->pos[1];
			return (sqrt(delta[0] * delta[0] + delta[1] * delta[1]));
		}
	}
	return (-1);
}

// Add side hit
void	draw_wall(int x, int wall_height)
{
	int	start;
	int	end;
	int	side;

	start = -wall_height / 2 + HEIGHT / 2;
	if (start < 0)
		start = 0;
	end = wall_height / 2 + HEIGHT / 2;
	if (end >= HEIGHT)
		end = HEIGHT -1;
	while (start < end)
		my_pixel_put(&var()->disp_3d, x, start++, 0x00FF00);
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
