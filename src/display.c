/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:58:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/17 18:18:43 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// int	display_win(void)
// {
// 	t_var	data;

// 	data.mlx = mlx_init();
// 	if (!data.mlx)
// 		clean_exit(WIN_ERR, 3);
// 	data.win = mlx_new_window(data.mlx, 1680, 1680, "cub3D");
// 	if (!data.win)
// 		clean_exit(WIN_ERR, 3);
// 	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
// 	mlx_hook(data.win, 17, 1L << 17, mlx_loop_end, data.mlx);
// 	mlx_loop(data.mlx);
// 	return (0);
// }
