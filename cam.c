/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/30 16:45:56 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	make_all_false(void)
{
	var()->w_key = false;
	var()->a_key = false;
	var()->s_key = false;
	var()->d_key = false;
	var()->right = false;
	var()->left = false;
}

// OLD VERSION JUST IN CASE
/* void	bound_checker(double dest_x, double dest_y)
{
	int	x;
	int	y;

	x = floor(dest_x);
	y = floor(dest_y);
	if (dest_x <= 0 || dest_x >= var()->disp.width \
	|| dest_y <= 0 || dest_y >= var()->disp.height \
	|| !var()->map.cmap[y] || !var()->map.cmap[y][x])
		return ;
	if (var()->map.cmap[y][x] == '1')
	{
		if (var()->map.cmap[y][(int)floor(var()->player.pos[0])] != '1')
			var()->player.pos[1] = dest_y;
		else if (var()->map.cmap[(int)floor(var()->player.pos[1])][x] != '1')
			var()->player.pos[0] = dest_x;
		else
			return ;
	}
	else
	{
		var()->player.pos[0] = dest_x;
		var()->player.pos[1] = dest_y;
	}
	cube_mker(var()->map.cmap);
} */
