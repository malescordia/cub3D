/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:58:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/29 20:03:07 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Initialises mlx & window
void	init_display(t_disp *disp)
{
	disp->width = ft_strlen(var()->map.cmap[0]) * CELL_SIZE;
	disp->height = get_2d_len(var()->map.cmap) * CELL_SIZE;
	disp->bit_pix = sizeof(int);
	disp->mlx = mlx_init();
	if (!disp->mlx)
		clean_exit(WIN_ERR, 3);
	disp->win = mlx_new_window(disp->mlx, disp->width, disp->height, "cub3D");
	if (!disp->win)
		clean_exit(WIN_ERR, 3);
	init_img(disp);
}

// Initialises new image
void	init_img(t_disp *disp)
{
	disp->img = mlx_new_image(disp->mlx, disp->width, disp->height);
	if (!disp->img)
		clean_exit(IMG_ERR, 3);
	if (disp->img_addr)
	{
		free(disp->img_addr);
		disp->img_addr = NULL;
	}
}

// Puts each pixel to the img address
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
