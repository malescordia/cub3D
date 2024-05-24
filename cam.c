/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/24 22:24:02 by cbouvet          ###   ########.fr       */
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
					//mlx_pixel_put(var()->disp.mlx, var()->disp.win, var()->player.pos[0] * CELL_SIZE, var()->player.pos[1] * CELL_SIZE, 0x00FF00);
			}
			else
				draw_cell(&var()->disp, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

void	draw_cell(t_disp *disp, int x, int y, int clr)
{
	int		i;
	int		j;
	//char	*pxl;

	i = 0;
	/* if (x == var()->player.pos[0] && y == var()->player.pos[1])
		put_player(disp, x, y, 0x00FF00); */
	x *= CELL_SIZE;
	y *= CELL_SIZE;
	while (i < CELL_SIZE)
	{
		j = 0;
		while (j < CELL_SIZE)
		{
			mlx_pixel_put(disp->mlx, disp->win, x + j, y + i, clr);
			/* disp->img_addr = mlx_get_data_addr(disp->img, &disp->bit_pix, &disp->width, &disp->endian);
			pxl = disp->img_addr + ((y + i) * disp->width + (x + j) * (disp->bit_pix / 8));
			*(unsigned int *)pxl = clr; */
			j++;
		}
		i++;
	}
}

void	put_player(t_disp *disp, int x, int y, int clr)
{
	int		i;
	int		j;
	//char	*pxl;

	i = 0;
	x *= CELL_SIZE;
	y *= CELL_SIZE;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			mlx_pixel_put(disp->mlx, disp->win, x + j, y + i, clr);
			/* disp->img_addr = mlx_get_data_addr(disp->img, &disp->bit_pix, &disp->width, &disp->endian);
			pxl = disp->img_addr + ((y + i) * disp->width + (x + j) * (disp->bit_pix / 8));
			*(unsigned int *)pxl = clr; */
			j++;
		}
		i++;
	}
}
