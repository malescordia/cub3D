/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:15:44 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/06 13:33:31 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	cub3d_maker(t_player *player)
{
	int		i;
	int		step[2];
	int		wall_height;
	double	perp_dist;

	i = 0;
	while (i < WIDTH)
	{
		//printf("----------------\nAPRES:\n");
		//printf("i - %i\n", i);
		set_variables(player, (double)(2 * i / (double)WIDTH -1));
		step[0] = step_incr(player, 0);
		step[1] = step_incr(player, 1);
		/* printf("step[0] - %i | step[1]: %i\n", step[0], step[1]);
		printf("side_dist[0] - %f | side_dist[1]: %f\n", player->side_dist[0], player->side_dist[1]);
		exit(0); */
		perp_dist = raycaster(player, step[0], step[1]);
		wall_height = (int)((double)HEIGHT / perp_dist);
		/* printf("side_dist[0] - %f | side_dist[1]: %f\n", player->side_dist[0], player->side_dist[1]);
		printf("wall[0] - %i | wall[1]: %i\n", player->wall[0], player->wall[1]);
		printf("side - %i\n", player->side);
		printf("perp_dist - %f\n", perp_dist);
		printf("wall_height - %i\n", wall_height);
		exit (0); */
		visual_render(player, i, wall_height);
		i++;
	}
	//exit(printf("EXITING\n"));
	mlx_put_image_to_window(var()->mlx, var()->disp_3d.win, var()->disp_3d.img, 0, 0);
}

void	set_variables(t_player *player, double cam)
{
	double	rad;
	double	new_dir;

	new_dir = player->dir + 270;
	if (new_dir >  360)
		new_dir -= 360;
	rad = new_dir * PI / 180;
	player->dir_arr[0] = cos(rad);
	player->dir_arr[1] = sin(rad);
	player->plane[0] = -player->dir_arr[1] * FOV;
	player->plane[1] = player->dir_arr[0] * FOV;
	player->ray[0] = player->dir_arr[0] + player->plane[0] * cam;
	player->ray[1] = player->dir_arr[1] + player->plane[1] * cam;
	player->wall[0] = (int)player->pos[0];
	player->wall[1] = (int)player->pos[1];
	player->delta[0] = fabs(1.0 / player->ray[0]);
	player->delta[1] = fabs(1.0 / player->ray[1]);

	/* printf("dir - %f\n", player->dir);
	printf("new_dir - %f\n", new_dir);
	printf("rad - %f\n", rad);
	printf("dir_arr[0] - %f | dir_arr[1]: %f\n", player->dir_arr[0], player->dir_arr[1]);
	printf("plane[0] - %f | plane[1]: %f\n", player->plane[0], player->plane[1]);
	printf("cam: %f\n", cam);
	printf("ray[0] - %f | ray[1]: %f\n", player->ray[0], player->ray[1]);
	printf("wall[0] - %i | wall[1]: %i\n", player->wall[0], player->wall[1]);
	printf("delta[0] - %f | delta[1]: %f\n", player->delta[0], player->delta[1]);
	exit(0); */
}

int	step_incr(t_player *player, int axis)
{
	if (player->ray[axis] < 0)
	{
		player->side_dist[axis] = (player->pos[axis] - \
		(double)player->wall[axis]) * player->delta[axis];
		return (-1);
	}
	player->side_dist[axis] = ((double)player->wall[axis] + 1.0 - \
	player->pos[axis]) * player->delta[axis];
	return (1);
}

double	raycaster(t_player *player, int step_x, int step_y)
{
	while (var()->map.cmap[player->wall[1]][player->wall[0]] != '1')
	{
		if (player->side_dist[0] < player->side_dist[1])
		{
			player->side_dist[0] += player->delta[0];
			player->wall[0] += step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist[1] += player->delta[1];
			player->wall[1] += step_y;
			player->side = 1;
		}
	}
	if (!player->side)
		return (player->side_dist[0] - player->delta[0]);
	return (player->side_dist[1] - player->delta[1]);
}
