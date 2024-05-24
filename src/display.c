/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:58:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/24 16:41:44 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	display_win(void)
{
    int     win_width;
    int     win_height;

    win_width = ft_strlen(var()->map.cmap[0]) * CELL_SIZE;
    win_height = get_2d_len(var()->map.cmap) * CELL_SIZE;

	var()->mlx = mlx_init();
	if (!var()->mlx)
		clean_exit(WIN_ERR, 3);
	var()->win = mlx_new_window(var()->mlx, win_width, win_height, "cub3D");
	if (!var()->win)
		clean_exit(WIN_ERR, 3);
    render_map(var());
	mlx_hook(var()->win, 2, 1L << 0, key_press, var());
	mlx_hook(var()->win, 17, 1L << 17, mlx_loop_end, var()->mlx);
	mlx_loop(var()->mlx);
	return (0);
}
