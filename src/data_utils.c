/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:24:29 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/16 16:22:25 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_line_nb(int fd)
{
	int		lines;

	lines = 0;
	while (!EOF)
	{
		get_next_line(fd);
		lines++;
	}
	return (lines);
}

int	tx_complete(t_map *map)
{
	if (!map->ntx || !map->etx || !map->wtx || !map->stx
		|| !map->fhex || !map->chex)
		return (0);
	return (1);
}

int	skip_sep(char *str, int i)
{
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	return (i);
}

int	is_separator(char *content)
{
	if (skip_sep(content, 0) != (int)ft_strlen(content))
		return (0);
	return (1);
}

int	is_map(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i] != '0' && content[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
