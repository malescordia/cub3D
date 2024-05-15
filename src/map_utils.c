/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:24:44 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/15 20:06:42 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* returns map length */
int	get_2d_len(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	return (i);
}

/* return length until end of str or '\n' is found */
int	strlen_until_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

/* receives a line and in order to find out if there is anything is not a '1', ' ' or '\n'
    return 0 if all is gud
	return -1 if condition is not ok */
int	check_borders(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->cmap[i][j])
	{
		if (map->cmap[i][j] != '1' && map->cmap[i][j] != ' ' && map->cmap[i][j] != '\n')
			clean_exit(BAD_MAP, 2);
		j++;
	}
	return (0);
}

/* check the indexes above given coordinate (same column)
	return 0 if a '1' is found
	return -1 if a space or edge of map is reached before a '1' */
int	check_up(t_map *map, int i, int j)
{
	while (i > 0)
	{
		if (map->map[i - 1][j] && map->map[i - 1][j] == '1')
			return (0);
		if (map->map[i - 1][j] && map->map[i - 1][j] == ' ')
			return (-1);
		i--;
	}
	return (-1);
}

/* check the indexes bellow given coordinate (same column)
	return 0 if a '1' is found
	return -1 if a space or edge of map is reached before a '1' */
int	check_down(t_map *map, int i, int j)
{
	while (i < get_2d_len(map->map))
	{
		if (map->map[i + 1][j] && map->map[i + 1][j] == '1')
			return (0);
		if (map->map[i + 1][j] && map->map[i + 1][j] == ' ')
			return (-1);
		i++;
	}
	return (-1);
}
