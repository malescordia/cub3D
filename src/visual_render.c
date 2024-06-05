/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:55:27 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/05 21:20:59 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	visual_render(t_player *player, int i, double wall_height)
{
	int	j;
	int	clr;
	int	up_pt;
	int	down_pt;

	up_pt = (-wall_height + HEIGHT) / 2;
	if (up_pt < 0)
		up_pt = 0;
	down_pt = (wall_height + HEIGHT) / 2;
	if (down_pt >= HEIGHT)
		down_pt = HEIGHT;
	j = 0;
	clr = 0xFFFF00;
	while (j < up_pt)
		my_pixel_put(&var()->disp_3d, i, j++, 0x000000);
	while (j < down_pt)
	{
		if (player->side && player->wall[1] < player->pos[1])
			clr = 0x0000FF; // north;
		else if (player->side && player->wall[1] > player->pos[1])
			clr = 0xFF0000; // south
		else if (!player->side && player->wall[0] < player->pos[0])
			clr = 0x00FF00; // west
		my_pixel_put(&var()->disp_3d, i, j++, clr);
	}
	while (j < HEIGHT)
		my_pixel_put(&var()->disp_3d, i, j++, 0x000000);
}
