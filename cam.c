/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/29 16:54:20 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	hooks_test(void)
{
	double dest[2];

	dest[0] = var()->player.pos[0];
	dest[1] = var()->player.pos[1];
	if (var()->w_key)
	{
		dest[0] += sin(var()->player.dir * PI / 180) * MV_SPEED;
		dest[1] += -cos(var()->player.dir * PI / 180) * MV_SPEED;
	}
	if (var()->s_key)
	{
		dest[0] -= sin(var()->player.dir * PI / 180) * MV_SPEED;
		dest[1] -= -cos(var()->player.dir * PI / 180) * MV_SPEED;
	}
	if (var()->a_key)
	{
		dest[0] -= cos(var()->player.dir * PI / 180) * MV_SPEED;
		dest[1] -= sin(var()->player.dir * PI / 180) * MV_SPEED;
	}
	if (var()->d_key)
	{
		dest[0] += cos(var()->player.dir * PI / 180) * MV_SPEED;
		dest[1] += sin(var()->player.dir * PI / 180) * MV_SPEED;
	}
	bound_checker(dest[0], dest[1]);
}


void	hooks_test_rot(void)
{
	double	new_dir;

	if (var()->left)
	{
		var()->left = false;
		var()->player.dir -= 30;
		new_dir = var()->player.dir;
		printf("new dir is %f\n", var()->player.dir);
		if (new_dir < 0)
			var()->player.dir = 360 - (new_dir * (-1));
		printf("new dir is %f\n", var()->player.dir);
	}
	if (var()->right)
	{
		var()->right = false;
		var()->player.dir += 30;
		new_dir = var()->player.dir;
		if (new_dir > 360)
			var()->player.dir = (360 - new_dir) * (-1);
		printf("new dir is %f\n", var()->player.dir);
	}
	if (var()->player.dir == 360)
		var()->player.dir = 0;
	cube_mker(var()->map.cmap);
}
