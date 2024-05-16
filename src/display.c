/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:58:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/16 14:41:55 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* tested */
int	display_win(void)
{
	t_var	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		clean_exit(WIN_ERR, 3);
	data.win = mlx_new_window(data.mlx, 1680, 1680, "cub3D");
	if (!data.win)
		clean_exit(WIN_ERR, 3);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 17, 1L << 17, mlx_loop_end, data.mlx); // for X and minimizing
	mlx_loop(data.mlx);
	return (0);
}
