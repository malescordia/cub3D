/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/29 15:11:44 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	hooks_test(void)
{
	double dest[2];
	double	incr[2];

	dest[0] = var()->player.pos[0];
	dest[1] = var()->player.pos[1];
	incr[0] = cos(var()->player.dir * PI / 180) * MV_SPEED;
	incr[1] = sin(var()->player.dir * PI / 180) * MV_SPEED;
	if (var()->w_key)
	{
		dest[0] += incr[0];
		dest[1] += incr[1];
	}
	bound_checker(dest[0], dest[1]);
	return (0);
}
