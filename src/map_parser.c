/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:49:02 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/16 16:19:19 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* check if map only contains valid characters
    return -1 otherwise */
int	check_characters(char **map)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = " NEWSFC\n";
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && ft_strchr(str,
					map[i][j]) == 0)
				clean_exit(BAD_MAP, 2);
			j++;
		}
		i++;
	}
	return (check_line(map));
}

/* check each line to ensure it starts and ends with '1'
	return -1 is this condition is not ok */
int	check_line(char **map)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (map[i])
	{
		start = 0;
		end = ft_strlen(map[i]) - 1;
		while (map[i][start] == ' ')
			start++;
		while (map[i][end] == ' ' || map[i][end] == '\n')
			end--;
		if (map[i][start] != '1' || map[i][end] != '1')
			clean_exit(BAD_MAP, 2);
		i++;
	}
	return (check_column(map));
}

/* check if each '0' has a '1' above or bellow it
    a loop iterates down to check up
    another loop iterates up to check down *IM A GENIUS*
	return -1 if this condition is not ok */
int	check_column(char **map)
{
	int	j;
	int	start;
	int	end;

	start = 0;
	end = get_2d_len(map) - 1;
	if (check_borders(map, start) == -1 || check_borders(map, end) == -1)
		clean_exit(BAD_MAP, 2);
	while (map[start] && start <= end)
	{
		j = 1;
		while (map[start][j])
		{
			if (map[start][j] == '0' && check_up(map, start, j) == -1)
				clean_exit(BAD_MAP, 2);
			j++;
		}
		start++;
	}
	while (end >= 0 && map[end])
	{
		j = 1;
		while (map[end][j])
		{
			if (map[end][j] == '0' && check_down(map, end, j) == -1)
				clean_exit(BAD_MAP, 2);
			j++;
		}
		end--;
	}
	return (kinda_floodfill(map));
}

int	kinda_floodfill(char **map)
{
	int		i;
	int		j;
	char	*str;

	str = "NEWS01";
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || ft_strchr("NEWS", map[i][j]))
			{
				if (j + 1 > strlen_until_newline(map[i - 1])
					|| j + 1 > strlen_until_newline(map[i + 1])
					|| ft_strchr(str, map[i - 1][j]) == 0
					|| ft_strchr(str, map[i + 1][j]) == 0
					|| ft_strchr(str, map[i][j - 1]) == 0
					|| ft_strchr(str, map[i][j + 1]) == 0)
					clean_exit(BAD_MAP, 2);
			}
			j++;
		}
		i++;
	}
	return (check_player(map));
}

int	check_player(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NEWS", map[i][j]))
			{
				if (player == 1)
					clean_exit(BAD_MAP, 2);
				player = 1;
			}
			j++;
		}
		i++;
	}
	if (player == 0)
		clean_exit(BAD_MAP, 2);
	return (0);
}