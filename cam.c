/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/27 17:08:12 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	hooks_handler(void)
{
	if (var()->left)
		var()->left = false;
	if (var()->right)
		var()->left = false;
	if (var()->w_key)
	{
		var()->w_key = false;
		bound_checker(1, var()->disp.height, var()->player.pos[1] - 0.1);
	}
	if (var()->a_key)
	{
		var()->a_key = false;
		bound_checker(0, var()->disp.width, var()->player.pos[0] - 0.1);
	}
	if (var()->s_key)
	{
		var()->s_key = false;
		bound_checker(1, var()->disp.height, var()->player.pos[1] + 0.1);
	}
	if (var()->d_key)
	{
		var()->d_key = false;
		bound_checker(0, var()->disp.width, var()->player.pos[0] + 0.1);
	}
	return (0);
}

void	bound_checker(int index, int axis, double target_pos)
{
	int	fl;
	int	cl;

	fl = floor(var()->player.pos[index]);
	cl = ceil(var()->player.pos[index]);
	printf("cl %i | content %i | pos %f | target %f\n", fl, var()->map.imap[index][cl], var()->player.pos[index], target_pos);
	if (target_pos <= 0 || target_pos >= axis)
		return ;
	if (!var()->map.imap[index][fl] || !var()->map.cmap[index][cl])
		return ;
	if (var()->map.imap[index][fl] == 1 && target_pos <= fl)
		return ;
	if (var()->map.imap[index][cl] == 1 && target_pos >= cl)
		return ;
	var()->player.pos[index] = target_pos;
	cube_mker(var()->map.cmap);
}
