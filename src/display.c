/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:58:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/24 21:43:35 by cbouvet          ###   ########.fr       */
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

void	init_img(t_disp *disp)
{
	disp->img = mlx_new_image(disp->mlx, disp->width, disp->height);
	if (!disp->img)
		clean_exit(IMG_ERR, 3);
	disp->img_addr = NULL;
}
