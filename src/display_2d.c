/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 19:18:28 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/25 21:37:57 by cbouvet          ###   ########.fr       */
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
}

void	my_pixel_put(t_disp *disp, int x, int y, int clr)
{
	char	*pxl;

	if (x < 0 || x >= disp->width || y < 0 || y >= disp->height)
		return ;
	disp->img_addr = mlx_get_data_addr(disp->img, &disp->bit_pix, \
	&disp->width, &disp->endian);
	pxl = disp->img_addr + (y * disp->width + x * (disp->bit_pix / 8));
	if (pxl)
		*(unsigned int *)pxl = clr;
}
