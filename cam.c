/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/24 17:51:45 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

// Recreate the display functions to see if they work out

//MLX DISPLAY + WIN DISPLAY
void	init_display(t_disp *disp)
{
	disp->width = ft_strlen(var()->map.cmap[0]) * CELL_SIZE;
	disp->height = get_2d_len(var()->map.cmap) * CELL_SIZE;

	disp->mlx = mlx_init();
	if (!disp->mlx)
		clean_exit(WIN_ERR, 3);
	disp->win = mlx_new_window(disp->mlx, disp->width, disp->height, "cub3D");
	if (!disp->win)
		clean_exit(WIN_ERR, 3);
}

//WIN DISPLAY
char	*

//IMG DISPLAY
