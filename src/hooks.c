/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:59:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/27 19:49:03 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Sets bool to true if key is pressed
int	key_press(int code)
{
	if (code == 65361)
		var()->left = true;
	else if (code == 65363)
		var()->right = true;
	else if (code == 'w' || code == 'W')
		var()->w_key = true;
	else if (code == 'a' || code == 'A')
		var()->a_key = true;
	else if (code == 's' || code == 'S')
		var()->s_key = true;
	else if (code == 'd' || code == 'D')
		var()->d_key = true;
	else if (code == 65307)
		clean_exit(NULL, 0);
	return (0);
}

// Creates destination according to true bool + sends to checker
int	hooks_handler(void)
{
	var()->player.dir[0] = var()->player.pos[0];
	var()->player.dir[1] = var()->player.pos[1];
	if (var()->left)
		var()->left = false;
	if (var()->right)
		var()->left = false;
	if (var()->w_key)
		var()->player.dir[1] -= 0.1;
	if (var()->a_key)
		var()->player.dir[0] -= 0.1;
	if (var()->s_key)
		var()->player.dir[1] += 0.1;
	if (var()->d_key)
		var()->player.dir[0] += 0.1;
	bound_checker(&var()->player);
	return (0);
}

// Checks if destination is within bounds + creates new image
void	bound_checker(t_player *player)
{
	int	x;
	int	y;

	var()->w_key = false;
	var()->a_key = false;
	var()->s_key = false;
	var()->d_key = false;
	x = floor(player->dir[0]);
	y = floor(player->dir[1]);
	if (player->dir[0] <= 0 || player->dir[0] >= var()->disp.width \
	|| player->dir[1] <= 0 || player->dir[1] >= var()->disp.height)
		return ;
	if (!var()->map.cmap[y] || !var()->map.cmap[y][x])
		return ;
	if (var()->map.cmap[y][x] == '1')
		return ;
	var()->player.pos[0] = player->dir[0];
	var()->player.pos[1] = player->dir[1];
	cube_mker(var()->map.cmap);
}
