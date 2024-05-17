/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/17 11:52:00 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

/* might come in handy */

// int	get_newsfc(t_map *map, char *line)
// {
// 	char	**split;
// 	split = ft_split(line, ' ');
//     // need to include a function here to check if tex / color code has already been saved
//     // since this is in a loop it would get us an infinite loop
// 	if (!ft_strncmp(split[0], "NO", 2) && !map->ntx && !split[2] && ft_strlen(split[0]) == 2)
// 		map->ntx = ft_strdup(split[1]);
// 	else if (!ft_strncmp(split[0], "EA", 2) && !map->etx && !split[2] && ft_strlen(split[0]) == 2)
// 		map->etx = ft_strdup(split[1]);
// 	else if (!ft_strncmp(split[0], "WE", 2) && !map->wtx && !split[2] && ft_strlen(split[0]) == 2)
// 		map->wtx = ft_strdup(split[1]);
// 	else if (!ft_strncmp(split[0], "SO", 2) && !map->stx && !split[2] && ft_strlen(split[0]) == 2)
// 		map->stx = ft_strdup(split[1]);
// 	else if (!ft_strncmp(split[0], "F", 1) && !map->ftx && !split[2] && ft_strlen(split[0]) == 1)
// 		map->ftx = ft_strdup(split[1]);
// 	else if (!ft_strncmp(split[0], "C", 1) && !map->ctx && !split[2] && ft_strlen(split[0]) == 1)
// 		map->ctx = ft_strdup(split[1]);
// 	return (0);
// }