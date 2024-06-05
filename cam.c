/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/05 15:18:39 by cbouvet          ###   ########.fr       */
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

/* void	camera_plane(t_player *player)
{
	int		i;
	int		wall_height;
	double	cam;
	double	wall_dist;
	double	ray_angle;

	i = 0;
	printf("90: %.2f\n", player->dir);
	printf("7.5: %.2f\n", player->pos[0]);
	printf("2.5: %.2f\n", player->pos[1]);
	while (i < var()->disp_3d.width)
	{
		cam = 2 * i / (double)WIDTH -1;
		ray_angle = player->dir + FOV * cam;
		player->ray[0] = cos(ray_angle * PI / 180);
		player->ray[1] = sin(ray_angle * PI / 180);
		printf("-1.0 - %f\n", cam);
		printf("30 - %f\n", ray_angle);
		printf("0.86602540378 - %f\n", player->ray[0]);
		printf(" 0.5 - %f\n", player->ray[1]);
		wall_dist = cast_ray(player);
		printf("0.707 - %f\n", wall_dist);
		if (wall_dist != -1)
		{
			wall_height = (HEIGHT / wall_dist);
			//printf("848 - %i\n", wall_height);
			//exit(0);
			//set_variables(player);
			draw_wall(i, wall_height);
		}
		i++;
	}
	mlx_clear_window(var()->mlx, var()->disp_3d.win);
	mlx_put_image_to_window(var()->mlx, var()->disp_3d.win, \
	var()->disp_3d.img, 0, 0);
} */

/* void	camera_plane(t_player *player)
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
		ray_angle = player->dir + (player->plane * PI / 180) * cam;
		player->ray[0] = cos(ray_angle);
		player->ray[1] = sin(ray_angle);
		wall_dist = cast_ray(player, ray_angle);
		if (wall_dist != -1)
		{
			wall_height = (int)(HEIGHT / wall_dist);
			draw_wall(i, wall_height);
		}
		i++;
	}
	mlx_clear_window(var()->mlx, var()->disp_3d.win);
	mlx_put_image_to_window(var()->mlx, var()->disp_3d.win, \
	var()->disp_3d.img, 0, 0);
} */
/*
 double	cast_ray(t_player *player)
{
	double	pos[2];
	double	delta[2];

	pos[0] = (int)player->pos[0];
	pos[1] = (int)player->pos[1];
	while (1)
	{
		pos[0] += player->ray[0];
		pos[1] += player->ray[1];
		if (pos[1] < 0 || pos[1] > get_2d_len(var()->map.cmap) || \
		pos[0] < 0 || pos[0] > ft_strlen(var()->map.cmap[(int)pos[1]]))
			break ;
		if (var()->map.cmap[(int)pos[1]][(int)pos[0]] == '1')
		{
			printf("8 - %f\n",pos[0]);
			printf("3 - %f\n", pos[1]);
			delta[0] = (int)pos[0] - player->pos[0];
			delta[1] = (int)pos[1] - player->pos[1];
			printf("0.5 - %f\n",delta[0]);
			printf("0.5 - %f\n", delta[1]);
			return (sqrt(delta[0] * delta[0] + delta[1] * delta[1]));
		}
	}
	return (-1);
} */



/* double	cast_ray(t_player *player, double ray_angle)
{
    int		map_pos[2];
    double	side_dist[2];
    double	delta_dist[2];
    int		step[2];
    int		hit;
    int		side;

	(void)ray_angle;
    map_pos[0] = (int)player->pos[0];
    map_pos[1] = (int)player->pos[1];

    delta_dist[0] = fabs(1 / player->ray[0]);
    delta_dist[1] = fabs(1 / player->ray[1]);

    if (player->ray[0] < 0)
    {
        step[0] = -1;
        side_dist[0] = (player->pos[0] - map_pos[0]) * delta_dist[0];
    }
    else
    {
        step[0] = 1;
        side_dist[0] = (map_pos[0] + 1.0 - player->pos[0]) * delta_dist[0];
    }

    if (player->ray[1] < 0)
    {
        step[1] = -1;
        side_dist[1] = (player->pos[1] - map_pos[1]) * delta_dist[1];
    }
    else
    {
        step[1] = 1;
        side_dist[1] = (map_pos[1] + 1.0 - player->pos[1]) * delta_dist[1];
    }

    hit = 0;
    while (!hit)
    {
        if (side_dist[0] < side_dist[1])
        {
            side_dist[0] += delta_dist[0];
            map_pos[0] += step[0];
            side = 0;
        }
        else
        {
            side_dist[1] += delta_dist[1];
            map_pos[1] += step[1];
            side = 1;
        }

        if (var()->map.cmap[map_pos[1]][map_pos[0]] == '1')
            hit = 1;
    }

    if (side == 0)
        return ((map_pos[0] - player->pos[0] + (1 - step[0]) / 2) / player->ray[0]);
    else
        return ((map_pos[1] - player->pos[1] + (1 - step[1]) / 2) / player->ray[1]);
} */

/* void	set_variables(t_player *player)
{

	step[0] = 1;
	step[1] = 1;
	collision = 0;
	delta[0] = fabs(1 / player->ray[0]);
	delta[1] = fabs(1 / player->ray[1]);
	pos[0] = (int)player->pos[0];
	pos[1] = (int)player->pos[1];
	if (player->ray[0] < 0)
	{
		step[0] *= -1;
		side_dist[0] = (player->pos[0] - pos[0]) * delta[0];
	}
	else
		side_dist[0] = (pos[0] + 1.0 - player->pos[0]) * delta[0];
	if (player->ray[1] < 0)
	{
		step[1] *= -1;
		side_dist[1] = (player->pos[1] - pos[1]) * delta[1];
	}
	else
		side_dist[1] = (pos[1] + 1.0 - player->pos[1]) * delta[1];

	while (!collision)
	{
		if (side_dist[0] < side_dist[1])
		{
			side_dist[0] += delta[0];
			pos[0] += step[0];
			side = 0;
		}
		else
		{
			side_dist[1] += delta[1];
			pos[1] += step[1];
			side = 1;
		}
		if (var()->map.imap[pos[0]][pos[1]] > 0)
			collision = 1;
	}
	if (!side)
		perp_dist = side_dist[0] - delta[0];
	else
		perp_dist = side_dist[1] - delta[1];
} */

// Add side hit
/* void	draw_wall(int x, int start, int end)
{
	int	i;

	i = 0;
	if (start < 0)
		start = 0;
	if (end > HEIGHT)
		end = HEIGHT;
	printf("START: %i\n", start);
	printf("END: %i\n", end);
	while (i < start)
		my_pixel_put(&var()->disp_3d, x, i++, 0x000000);
	while (start < end)
		my_pixel_put(&var()->disp_3d, x, start++, 0x00FF00);
	while (end < HEIGHT)
		my_pixel_put(&var()->disp_3d, x, end++, 0xFFFFFF);
} */

/* void	draw_wall(int x, int wall_height)
{
    int	i;
    int	start;
    int	end;

    if (wall_height > HEIGHT)
        wall_height = HEIGHT;
    start = -wall_height / 2 + HEIGHT / 2;
    if (start < 0)
        start = 0;
    end = wall_height / 2 + HEIGHT / 2;
    if (end >= HEIGHT)
        end = HEIGHT - 1;
    i = 0;
    while (i < start)
        my_pixel_put(&var()->disp_3d, x, i++, 0x000000);
    while (start < end)
        my_pixel_put(&var()->disp_3d, x, start++, 0x00FF00);
    while (end < HEIGHT)
        my_pixel_put(&var()->disp_3d, x, end++, 0xFFFFFF);
} */

/* void	draw_camera_plane(double x, double y)
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
} */

/* void camera_plane(t_player *player)
{
    double rayDirX, rayDirY;
    int mapX, mapY;
    double sideDistX, sideDistY;
    double perpWallDist;
    int lineHeight;
    int drawStart, drawEnd;

    initialize_plane();

    for (int x = 0; x < WIDTH; x++) {
        // Calculate ray direction without the fishbowl effect
        rayDirX = cos((player->dir * PI / 180) + player->plane[0]) * (2 * x / (double)WIDTH - 1);
        rayDirY = sin((player->dir * PI / 180) + player->plane[1]) * (2 * x / (double)WIDTH - 1);

        // Calculate map position
        mapX = (int)player->pos[0];
        mapY = (int)player->pos[1];

        // Length of ray from one x or y-side to next x or y-side
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);

        // Calculate step and initial sideDist
        int stepX, stepY;
        if (rayDirX < 0) {
            stepX = -1;
			sideDistX = (player->pos[0] - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player->pos[0]) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
			sideDistY = (player->pos[1] - mapY) * deltaDistY;
        } else {
            stepY = 1;
			sideDistY = (mapY + 1.0 - player->pos[1]) * deltaDistY;
        }

        // Perform DDA
        int hit = 0;
		printf("stepx: %f\nstepy: %f\n", sideDistX, sideDistY);
        while (!hit) {
            // Jump to next map square, either in x-direction or y-direction
       		if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                player->side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                player->side = 1;
            }
            // Check if ray has hit a wall
            if (mapY >= 0 && mapY < get_2d_len(var()->map.cmap) &&
                mapX >= 0 && mapX < (int)ft_strlen(var()->map.cmap[mapY]) &&
                var()->map.cmap[mapY][mapX] == '1') {
                hit = 1;
				printf("X: %i | Y: %i\n", mapX, mapY);
            }
        }

        // Calculate distance projected on camera direction
        if (player->side == 0)
            perpWallDist = (mapX - player->pos[0] + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - player->pos[1] + (1 - stepY) / 2) / rayDirY;

        // Calculate height of line to draw on screen
        lineHeight = (int)(HEIGHT / perpWallDist);

        // Calculate lowest and highest pixel to fill in current stripe
        drawStart = -lineHeight / 2 + HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;
        drawEnd = lineHeight / 2 + HEIGHT / 2;
        if (drawEnd >= HEIGHT)
            drawEnd = HEIGHT - 1;

        // Draw the wall for the current column
        		double	wall_x;
		if (!player->side)
			wall_x = player->pos[1] + perpWallDist * rayDirY;
		else
			wall_x = player->pos[0] + perpWallDist * rayDirX;
		wall_x -= floor(wall_x);

		int i  = 0;
		while (i < HEIGHT)
		{
			if (i < drawStart)
				my_pixel_put(&var()->disp_3d, x, i, 0x000000);
			else if (i < drawEnd)
			{
				int	clr;
				if (player->side && mapY < player->pos[1])
					clr = 0xFF0000; // south
				else if (player->side && mapY > player->pos[1])
					clr = 0x0000FF; // north
				else if (!player->side && mapX < player->pos[0])
					clr = 0xA52A2A; // east
				else
					clr = 0x00FF00; // west
				my_pixel_put(&var()->disp_3d, x, i, clr);
			}
			else
				my_pixel_put(&var()->disp_3d, x, i, 0xFFFFFF);
			i++;
		}
    }
	//mlx_clear_window(var()->mlx, var()->disp_3d.win);
    mlx_put_image_to_window(var()->mlx, var()->disp_3d.win, var()->disp_3d.img, 0, 0);
} */


void	initialize_plane(void)
{
    double rad = var()->player.dir * PI / 180;

    // Initialize direction vector
    double dirX = cos(rad);
    double dirY = sin(rad);

    // Initialize camera plane
    double planeX = -dirY * FOV;
    double planeY = dirX * FOV;

    var()->player.plane[0] = planeX;
    var()->player.plane[1] = planeY;
}

void camera_plane(t_player *player)
{
    double rayDirX, rayDirY;
    int mapX, mapY;
    double sideDistX, sideDistY;
    double perpWallDist;
    int lineHeight;
    int drawStart, drawEnd;

	double rad = var()->player.dir * PI / 180;
	double dirX = cos(rad);
    double dirY = sin(rad);
	double	camera_x;

    initialize_plane();

    for (int x = 0; x < WIDTH; x++) {
        // Calculate ray direction without the fishbowl effect
		camera_x = (((double)(2 * x)) / (double)(WIDTH)) - 1;
		rayDirX = dirX + player->plane[0] * camera_x;
        rayDirY = dirY + player->plane[1] * camera_x;

        // Calculate map position
        mapX = (int)player->pos[0];
        mapY = (int)player->pos[1];

		 double deltaDistX;
		if (!rayDirX)
			deltaDistX = 1e30;
		else
     		deltaDistX = fabs(1.0 / rayDirX);

		double deltaDistY;
		if (!rayDirY)
			deltaDistY = 1e30;
		else
     		deltaDistY = fabs(1.0 / rayDirY);


        // Calculate step and initial sideDist
        int stepX, stepY;
        if (rayDirX < 0) {
            stepX = -1;
			sideDistX = (player->pos[0] - (double)mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = ((double)mapX + 1.0 - player->pos[0]) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
			sideDistY = (player->pos[1] - (double)mapY) * deltaDistY;
        } else {
            stepY = 1;
			sideDistY = ((double)mapY + 1.0 - player->pos[1]) * deltaDistY;
        }

        // Perform DDA
        int hit = 0;
        while (!hit) {
            // Jump to next map square, either in x-direction or y-direction
       		if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                player->side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                player->side = 1;
            }
            // Check if ray has hit a wall
            if (var()->map.cmap[mapY][mapX] == '1') {
                hit = 1;
            }
        }

        // Calculate distance projected on camera direction
        if (player->side == 0)
			perpWallDist = sideDistX - deltaDistX;
        else
            perpWallDist = sideDistY - deltaDistY;

        // Calculate height of line to draw on screen
        lineHeight = (int)((double)HEIGHT / perpWallDist);

        // Calculate lowest and highest pixel to fill in current stripe
        drawStart = (-lineHeight + HEIGHT) / 2;
        if (drawStart < 0)
            drawStart = 0;
        drawEnd = (lineHeight + HEIGHT) / 2;
        if (drawEnd >= HEIGHT)
            drawEnd = HEIGHT;

        // Draw the wall for the current column
		double	wall_x;
		if (!player->side)
			wall_x = player->pos[1] + perpWallDist * rayDirY;
		else
			wall_x = player->pos[0] + perpWallDist * rayDirX;
		wall_x -= floor(wall_x);

		int i  = 0;
		while (i < HEIGHT)
		{
			if (i < drawStart)
				my_pixel_put(&var()->disp_3d, x, i, 0x000000);
			else if (i < drawEnd)
			{
				int	clr;
				if (player->side && mapY < player->pos[1])
					clr = 0xFF0000; // south
				else if (player->side && mapY > player->pos[1])
					clr = 0x0000FF; // north
				else if (!player->side && mapX < player->pos[0])
					clr = 0xFFFF00; // east
				else
					clr = 0x00FF00; // west
				my_pixel_put(&var()->disp_3d, x, i, clr);
			}
			else
				my_pixel_put(&var()->disp_3d, x, i, 0xFFFFFF);
			i++;
		}


    }
	//mlx_clear_window(var()->mlx, var()->disp_3d.win);
    mlx_put_image_to_window(var()->mlx, var()->disp_3d.win, var()->disp_3d.img, 0, 0);
}

