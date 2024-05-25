/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/25 18:53:49 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

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
			{
				draw_cell(&var()->disp, j, i, 0x808080);
				if (ft_strchr("NEWS", map[i][j]))
					put_player(&var()->disp, j, i, 0x00FF00);
			}
			else
				draw_cell(&var()->disp, i, j, 0x000000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(var()->disp.mlx, var()->disp.win, var()->disp.img, 0, 0);
}

void	draw_cell(t_disp *disp, int x, int y, int clr)
{
	int		i;
	int		j;

	i = 0;
	x *= CELL_SIZE;
	y *= CELL_SIZE;
	while (i < CELL_SIZE)
	{
		j = 0;
		while (j < CELL_SIZE)
		{
			my_pixel_put(disp, x + j, y + i, clr);
			if (clr == 0x808080 && (j == CELL_SIZE -1 || i == CELL_SIZE -1 || !j || !i))
				my_pixel_put(disp, x + j, y + i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

void	put_player(t_disp *disp, int x, int y, int clr)
{
	int		i;
	int		j;

	i = 0;
	x *= CELL_SIZE;
	y *= CELL_SIZE;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_pixel_put(disp, x + j + (CELL_SIZE / 2), y + i + (CELL_SIZE / 2), clr);
			j++;
		}
		i++;
	}
}

void	my_pixel_put(t_disp *disp, int x, int y, int clr)
{
	char	*pxl;

	if (x < 0 || x >= disp->width || y < 0 || y >= disp->height)
        return;
	disp->img_addr = mlx_get_data_addr(disp->img, &disp->bit_pix, &disp->width, &disp->endian);
	pxl = (char *)(disp->img_addr + (y * disp->width + x * (disp->bit_pix / 8)));
	if (pxl)
		*(unsigned int *)pxl = clr;
}


