/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:31:28 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/28 14:56:24 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Initializes variables in player's struct
void	init_player(char **map)
{
	int	i;
	int	j;

	var()->player.fov = 40.0;
	var()->player.plane[0] = 0.0;
	var()->player.plane[1] = var()->player.fov / 100;
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
	if (ft_strchr("NS", facing))
		player->dir[0] = 0.0;
	else if (ft_strchr("EW", facing))
		player->dir[1] = 0.0;
	if (facing == 'N')
		player->dir[1] = 1.0;
	else if (facing == 'S')
		player->dir[1] = -1.0;
	else if (facing == 'E')
		player->dir[0] = 1.0;
	else if (facing == 'W')
		player->dir[0] = -1.0;
}
