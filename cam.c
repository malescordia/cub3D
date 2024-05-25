/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/25 21:13:25 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

// make primary map + save it
void	cube_mapper(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_cell(&var()->disp, j, i, 0x00002F);
			else if (map[i][j] == '0' || ft_strchr("NEWS", map[i][j]))
			{
				draw_cell(&var()->disp, j, i, 0x808080);
				if (ft_strchr("NEWS", map[i][j]))
					put_player(&var()->disp, j, i, 0x00FF00);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(var()->disp.mlx, var()->disp.win, \
	var()->disp.img, 0, 0);
}

// put player

// pixel put
