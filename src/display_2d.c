/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:18:28 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/06 12:17:04 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Recreate the display functions to see if they work out
void	cub2d_maker(char **map)
{
	int	i;
	int	j;

	i = 0;
	/* var()->player.plane = var()->player.dir - 90;
	if (var()->player.plane < 0)
		var()->player.plane = 360 - (var()->player.plane * (-1)); */
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_cell(&var()->disp_2d, j, i, 0x00002F);
			else if (map[i][j] == '0' || ft_strchr("NEWS", map[i][j]))
				draw_cell(&var()->disp_2d, j, i, 0x808080);
			j++;
		}
		i++;
	}
	printf("%p \n", var()->mlx);
	put_player(&var()->disp_2d, var()->player.pos[0], var()->player.pos[1]);
	mlx_put_image_to_window(var()->mlx, var()->disp_2d.win, \
	var()->disp_2d.img, 0, 0);
}

// Draws each cell and its bounds
void	draw_cell(t_disp *disp, int x, int y, int clr)
{
	int	i;
	int	j;

	i = 0;
	x *= CELL_SIZE;
	y *= CELL_SIZE;
	while (i < CELL_SIZE)
	{
		j = 0;
		while (j < CELL_SIZE)
		{
			my_pixel_put(disp, x + j, y + i, clr);
			if (clr == 0x808080 && (j == CELL_SIZE -1 || i == CELL_SIZE -1 \
			|| !j || !i))
				my_pixel_put(disp, x + j, y + i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

// Puts the player in the map
void	put_player(t_disp *disp, double x, double y)
{
	int		i;
	int		j;
	double	k;

	i = -3;
	x *= CELL_SIZE;
	y *= CELL_SIZE;
	while (i < 4)
	{
		j = -3;
		while (j < 4)
		{
			my_pixel_put(disp, x + j, y + i, 0x00FF00);
			j++;
		}
		i++;
	}
	k = 0;
	while (k <= (FOV * 50) / 2)
	{
		var()->player.fov_dir = var()->player.dir - k;
		draw_line(disp, x, y);
		k += 0.1;
	}
	k = 0;
	while (k < (FOV * 50) / 2)
	{
		var()->player.fov_dir = var()->player.dir + k;
		draw_line(disp, x, y);
		k += 0.1;
	}
}

// Draws line showing rotation direction
void	draw_line(t_disp *disp, double x, double y)
{
	while (var()->map.cmap[(int)(y / CELL_SIZE)][(int)(x / CELL_SIZE)] != '1')
	{
		x += sin(var()->player.fov_dir * PI / 180);
		y += -cos(var()->player.fov_dir * PI / 180);
		my_pixel_put(disp, x, y, 0x00FF00);
	}
}

/* void	draw_line(t_disp *disp, double x, double y)
{
	while (42)
	{
		x += sin(var()->player.fov_dir * PI / 180);
		y += -cos(var()->player.fov_dir * PI / 180);
		if (var()->map.cmap[(int)(y / CELL_SIZE)][(int)(x / CELL_SIZE)] == '1')
			break ;
		my_pixel_put(disp, x, y, 0x00FF00);
	}
} */
/* void	put_player(t_disp *disp, double x, double y)
{
	int		i;
	int		j;

	i = -3;
	x *= CELL_SIZE;
	y *= CELL_SIZE;
	while (i < 4)
	{
		j = -3;
		while (j < 4)
		{
			my_pixel_put(disp, x + j, y + i, 0x00FF00);
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	if (!var()->player.dir)
		i = -1;
	else if (var()->player.dir == 180)
		i = 1;
	else if (var()->player.dir == 90)
		j = 1;
	else if (var()->player.dir == 270)
		j = -1;
	draw_line(disp, x, y, j, i);
} */

/* void	draw_line(t_disp *disp, double x, double y, int x_mv, int y_mv)
{
	int	i;

	i = 0;
	while (i < 40)
	{
		x += x_mv;
		y += y_mv;
		my_pixel_put(disp, x, y, 0x00FF00);
		i++;
	}
} */

// Checks if destination is within bounds + creates new image
void	bound_checker(double dest_x, double dest_y)
{
	int	x;
	int	y;

	x = floor(dest_x);
	y = floor(dest_y);
	if (dest_x <= 0 || dest_x >= var()->disp_2d.width \
	|| dest_y <= 0 || dest_y >= var()->disp_2d.height \
	|| !var()->map.cmap[y] || !var()->map.cmap[y][x])
		return ;
	if (var()->map.cmap[y][x] != '1')
	{
		var()->player.pos[0] = dest_x;
		var()->player.pos[1] = dest_y;
	}
	else if (var()->map.cmap[y][(int)floor(var()->player.pos[0])] != '1')
		var()->player.pos[1] = dest_y;
	else if (var()->map.cmap[(int)floor(var()->player.pos[1])][x] != '1')
		var()->player.pos[0] = dest_x;
	else
		return ;
	if (var()->disp_2d.win)
		cub2d_maker(var()->map.cmap);
	//camera_plane(&var()->player);
	cub3d_maker(&var()->player);
}
