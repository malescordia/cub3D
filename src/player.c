/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:31:28 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/05 18:08:03 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Initializes variables in player's struct
void	init_player(char **map)
{
	int	i;
	int	j;

	var()->player.fov = 60.0;
	/* var()->player.plane = var()->player.dir - 90;
	if (var()->player.plane < 0)
		var()->player.plane = 360 - (var()->player.plane * (-1)); */
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NEWS", map[i][j]))
			{
				var()->player.pos[0] = j +0.5;
				var()->player.pos[1] = i +0.5;
				define_facing(&var()->player, map[i][j]);
				var()->player.fov_dir = var()->player.dir;
				return ;
			}
			j++;
		}
		i++;
	}
}

// Define facing direction vector
void	define_facing(t_player *player, char facing)
{
	if (facing == 'N')
		player->dir = 0.0;
	else if (facing == 'E')
		player->dir = 90.0;
	else if (facing == 'S')
		player->dir = 180.0;
	else if (facing == 'W')
		player->dir = 270.0;
}
