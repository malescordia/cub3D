/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/27 19:03:08 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	hooks_handler(void)
{
	double	target[2];

	target[0] = var()->player.pos[0];
	target[1] = var()->player.pos[1];
	if (var()->left)
		var()->left = false;
	if (var()->right)
		var()->left = false;
	if (var()->w_key)
	{
		var()->w_key = false;
		target[1] -= 0.1;
		bound_checker(target);
	}
	if (var()->a_key)
	{
		var()->a_key = false;
		target[0] -= 0.1;
		bound_checker(target);
	}
	if (var()->s_key)
	{
		var()->s_key = false;
		target[1] += 0.1;
		bound_checker(target);
	}
	if (var()->d_key)
	{
		var()->d_key = false;
		target[0] += 0.1;
		bound_checker(target);
	}
	return (0);
}

void	bound_checker(double target[2])
{
	int	x;
	int	y;
	int	x_target;
	int	y_target;

	x = floor(var()->player.pos[0]);
	y = floor(var()->player.pos[1]);
	x_target = floor(target[0]);
	y_target = floor(target[1]);
	if (target[0] <= 0 || target[0] >= var()->disp.width || target[1] <= 0 || target[1] >= var()->disp.height)
		return ;
	if (!var()->map.cmap[y_target] || !var()->map.cmap[y_target][x_target])
		return ;
	if (var()->map.cmap[y_target][x_target] == '1')
		return ;
	var()->player.pos[0] = target[0];
	var()->player.pos[1] = target[1];
	cube_mker(var()->map.cmap);
}
