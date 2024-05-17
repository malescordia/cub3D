/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/17 18:35:03 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	place_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NEWS", map[i][j]))
			{
				var()->player.xpos = j +1;
				var()->player.ypos = i +1;
				define_facing(&var()->player, map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	define_facing(t_player *player, char face)
{
	if (ft_strchr("NS", face))
		player->facing_deg[0] = 0;
	else if (ft_strchr("EW", face))
		player->facing_deg[1] = 0;
	if (face == 'N')
		player->facing_deg[1] = 1;
	else if (face == 'S')
		player->facing_deg[1] = -1;
	else if (face == 'E')
		player->facing_deg[0] = 1;
	else if (face == 'W')
		player->facing_deg[0] = -1;
}


