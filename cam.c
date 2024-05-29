/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/29 15:46:02 by cbouvet          ###   ########.fr       */
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
