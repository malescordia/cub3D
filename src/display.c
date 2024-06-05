/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:58:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/05 21:34:36 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Initialises mlx & window
void	init_display(t_disp *disp, int code, char *name)
{
	disp->width = WIDTH;
	disp->height = HEIGHT;
	disp->bit_pix = sizeof(int);
	if (!code)
	{
		disp->width = ft_strlen(var()->map.cmap[0]) * CELL_SIZE;
		disp->height = get_2d_len(var()->map.cmap) * CELL_SIZE;
	}
	var()->mlx = mlx_init();
	if (!var()->mlx)
		clean_exit(WIN_ERR, 3);
	disp->win = mlx_new_window(var()->mlx, disp->width, disp->height, name);
	if (!disp->win)
		clean_exit(WIN_ERR, 3);
	init_img(disp);
	init_hooks(disp);
}

// Initialises new image
void	init_img(t_disp *disp)
{
	disp->img = mlx_new_image(var()->mlx, disp->width, disp->height);
	if (!disp->img)
		clean_exit(IMG_ERR, 3);
	if (disp->img_addr)
	{
		free(disp->img_addr);
		disp->img_addr = NULL;
	}
}

// Sets hooks for window
void	init_hooks(t_disp *disp)
{
	mlx_hook(disp->win, 2, 1L << 0, key_press, NULL);
	mlx_hook(disp->win, 3, 1L << 1, key_release, NULL);
	mlx_hook(disp->win, 17, 1L << 17, mlx_loop_end, var()->mlx);
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
