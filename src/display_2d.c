/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:18:28 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/30 16:46:16 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Recreate the display functions to see if they work out
void	cube_mker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_cell(&var()->disp, j, i, 0x00002F);
			else if (map[i][j] == '0' || ft_strchr("NEWS", map[i][j]))
				draw_cell(&var()->disp, j, i, 0x808080);
			j++;
		}
		i++;
	}
	put_player(&var()->disp, var()->player.pos[0], var()->player.pos[1]);
	mlx_put_image_to_window(var()->disp.mlx, var()->disp.win, \
	var()->disp.img, 0, 0);
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
	draw_line(disp, x, y);
}

// Draws line showing rotation direction
void	draw_line(t_disp *disp, double x, double y)
{
	while (42)
	{
		x += sin(var()->player.dir * PI / 180);
		y += -cos(var()->player.dir * PI / 180);
		if (var()->map.cmap[(int)(y / CELL_SIZE)][(int)(x / CELL_SIZE)] == '1')
			break ;
		my_pixel_put(disp, x, y, 0x00FF00);
	}
}

// Checks if destination is within bounds + creates new image
void	bound_checker(double dest_x, double dest_y)
{
	int	x;
	int	y;

	x = floor(dest_x);
	y = floor(dest_y);
	if (dest_x <= 0 || dest_x >= var()->disp.width \
	|| dest_y <= 0 || dest_y >= var()->disp.height \
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
	cube_mker(var()->map.cmap);
}
