/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/06 17:40:47 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

// STEP 1: SUBSTITUTE THIS FOR LINE 199 IN CUB3D.H

int draw_texture(t_player *player, t_tex *tex, int wall_height, double	perp_dist, int j);

// STEP 2: COMMENT WHOLE VISUAL_RENDER.C AND INSERT THIS THERE

void	visual_render(t_player *player, int i, int wall_height, double	perp_dist)
{
	int	j;
	//int	clr;
	int	up_pt;
	int	down_pt;

	up_pt = (-wall_height + HEIGHT) / 2;
	if (up_pt < 0)
		up_pt = 0;
	down_pt = (wall_height + HEIGHT) / 2;
	if (down_pt >= HEIGHT)
		down_pt = HEIGHT;

	j = 0;

	while (j < HEIGHT)
	{
		if (j < up_pt)
			my_pixel_put(&var()->disp_3d, i, j, var()->map.c_clr);
		else if (j < down_pt)
		{
			int	clr;
			if (player->side && player->wall[1] < player->pos[1])
				clr = draw_texture(player, &var()->map.ntx, wall_height, perp_dist, j); // north;
			else if (player->side && player->wall[1] > player->pos[1])
				clr = draw_texture(player, &var()->map.stx, wall_height, perp_dist, j);  // south
			else if (!player->side && player->wall[0] < player->pos[0])
				clr = draw_texture(player, &var()->map.wtx, wall_height, perp_dist, j); // west
			else
				clr = draw_texture(player, &var()->map.etx, wall_height, perp_dist, j);
			if (clr != -1)
				my_pixel_put(&var()->disp_3d, i, j, clr);
		}
		else
			my_pixel_put(&var()->disp_3d, i, j, var()->map.f_clr);
		j++;
	}
}

int draw_texture(t_player *player, t_tex *tex, int wall_height, double	perp_dist, int j)
{
    int tex_x, tex_y;
    double wall_x;

    // Determine position on the wall to map to the texture
    if (player->side == 0)
        wall_x = player->pos[1] + perp_dist * player->ray[1];
    else
        wall_x = player->pos[0] + perp_dist * player->ray[0];
    wall_x -= floor(wall_x);

    // X coordinate on the texture
    tex_x = (int)(wall_x * (double)tex->width);
    if (player->side == 0 && player->ray[0] > 0)
		tex_x = tex->width - tex_x - 1;
    if (player->side == 1 && player->ray[1] < 0)
		tex_x = tex->width - tex_x - 1;

	// Y coordinate on the texture
    int d = j * 256 - HEIGHT * 128 + wall_height * 128;  // 256 and 128 factors to avoid floats
    tex_y = ((d * tex->height) / wall_height) / 256;

    // Ensure tex_x is within bounds
    if (tex_x < 0)
        tex_x = 0;
    if (tex_x >= tex->width)
        tex_x = tex->width - 1;
    // Ensure tex_y is within bounds
    if (tex_y < 0)
        tex_y = 0;
    if (tex_y >= tex->height)
        tex_y = tex->height - 1;

    // Get color from texture
    int color = ((int *)tex->pixel)[tex->width * tex_y + tex_x];
    // Return the color for the current row
    return color;
}
