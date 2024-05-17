/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:24:29 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/17 16:24:20 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	tx_complete(t_map *map)
{
	if (!map->ntx || !map->etx || !map->wtx || !map->stx
		|| !map->fhex || !map->chex)
		return (0);
	return (1);
}

int	skip_sep(char *str, int i)
{
	if (!str || !str[0])
		return (0);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || str[i] == '\n'))
		i++;
	return (i);
}

int	is_separator(char *txt)
{
	if (skip_sep(txt, 0) != (int)ft_strlen(txt))
		return (0);
	return (1);
}

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
