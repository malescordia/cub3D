/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/27 15:33:13 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	hooks_handler(void)
{
	if (var()->left)
	{
		printf("left pressed\n");
		var()->left = false;
	}
	if (var()->right)
	{
		printf("left pressed\n");
		var()->left = false;
	}
	if (var()->w_key)
	{
		var()->player.pos[1] -= 0.1;
		var()->w_key = false;
		cube_mker(var()->map.cmap);
	}
	if (var()->a_key)
	{
		var()->player.pos[0] -= 0.1;
		var()->a_key = false;
		cube_mker(var()->map.cmap);
	}
	if (var()->s_key)
	{
		var()->player.pos[1] += 0.1;
		var()->s_key = false;
		cube_mker(var()->map.cmap);
	}
	if (var()->d_key)
	{
		var()->player.pos[0] += 0.1;
		var()->d_key = false;
		cube_mker(var()->map.cmap);
	}
	return (0);
}
