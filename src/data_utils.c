/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:24:29 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/06 15:35:43 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Checks if each texture/clr has already been attributed
int	tx_complete(t_map *map)
{
	if (!map->ntx.name || !map->etx.name || !map->wtx.name || !map->stx.name
		|| map->f_clr == -1 || map->c_clr == -1)
		return (0);
	return (1);
}

// Returns the index of the next non-separator char
int	skip_sep(char *str, int i)
{
	if (!str || !str[0])
		return (0);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) \
	|| str[i] == ' ' || str[i] == '\n'))
		i++;
	return (i);
}

// Checks if a whole string is made of separators
int	is_separator(char *txt)
{
	if (skip_sep(txt, 0) != (int)ft_strlen(txt))
		return (0);
	return (1);
}

// Check if string is a map
int	is_map(char *txt)
{
	int	i;

	i = 0;
	while (txt[i])
	{
		if (txt[i] != '0' && txt[i] != '1' && txt[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
