/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:59:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/30 14:53:59 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Sets bool to true if key is pressed
int	key_press(int code)
{
	if (code == 65361)
		var()->left = true;
	if (code == 65363)
		var()->right = true;
	if (code == 'w' || code == 'W')
		var()->w_key = true;
	if (code == 'a' || code == 'A')
		var()->a_key = true;
	if (code == 's' || code == 'S')
		var()->s_key = true;
	if (code == 'd' || code == 'D')
		var()->d_key = true;
	if (code == 65307)
		clean_exit(NULL, 0);
	return (0);
}

// Sets bool to false if key is released
int	key_release(int code)
{
	if (code == 65361)
		var()->left = false;
	if (code == 65363)
		var()->right = false;
	if (code == 'w' || code == 'W')
		var()->w_key = false;
	if (code == 'a' || code == 'A')
		var()->a_key = false;
	if (code == 's' || code == 'S')
		var()->s_key = false;
	if (code == 'd' || code == 'D')
		var()->d_key = false;
	return (0);
}

// Checks if hooks were triggered
int	hooks_handler(void)
{
	if (!var()->w_key && !var()->a_key && !var()->s_key && \
	!var()->d_key && !var()->right && !var()->left)
		return (0);
	hooks_mvt(var()->player.pos[0], var()->player.pos[1]);
	hooks_rot();
	//make_all_false();
	return (0);
}

// Creates destination + sends to bound checker
void	hooks_mvt(double x_dest, double y_dest)
{
	if (var()->w_key)
	{
		x_dest += sin(var()->player.dir * PI / 180) * MV_SPEED;
		y_dest += -cos(var()->player.dir * PI / 180) * MV_SPEED;
	}
	if (var()->s_key)
	{
		x_dest -= sin(var()->player.dir * PI / 180) * MV_SPEED;
		y_dest -= -cos(var()->player.dir * PI / 180) * MV_SPEED;
	}
	if (var()->a_key)
	{
		x_dest -= cos(var()->player.dir * PI / 180) * MV_SPEED;
		y_dest -= sin(var()->player.dir * PI / 180) * MV_SPEED;
	}
	if (var()->d_key)
	{
		x_dest += cos(var()->player.dir * PI / 180) * MV_SPEED;
		y_dest += sin(var()->player.dir * PI / 180) * MV_SPEED;
	}
	bound_checker(x_dest, y_dest);
}

// Rotates direction + caps rotation + creates new image
void	hooks_rot(void)
{
	if (var()->left)
	{
		var()->player.dir -= ROT_DEG;
		if (var()->player.dir < 0)
			var()->player.dir = 360 - (var()->player.dir * (-1));
	}
	if (var()->right)
	{
		var()->player.dir += ROT_DEG;
		if (var()->player.dir > 360)
			var()->player.dir = (360 - var()->player.dir) * (-1);
	}
	cube_mker(var()->map.cmap);
}
