/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/17 18:19:38 by cbouvet          ###   ########.fr       */
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
				var()->player.xpos = j;
				var()->player.ypos = i;
				if (map[i][j] == 'N')
					var()->player.facing_deg = 0.1;
				else if (map[i][j] == 'E')
					var()->player.facing_deg = 1.0;
				else if (map[i][j] == 'S')
					var()->player.facing_deg = 0.-1;
				else if (map[i][j] == 'W')
					var()->player.facing_deg = -1.0;
				return ;
			}
			j++;
		}
		i++;
	}
}


