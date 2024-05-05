/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:49:17 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/05 17:35:29 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void free_matrix(char **matrix)
{
    int i;

    i = 0;
    while(matrix && matrix[i])
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}

void free_map(t_map *map)
{
    free(map->north);
    free(map->south);
    free(map->west);
    free(map->east);
    free(map->floor);
    free(map->ceiling);
    free_matrix(map->map);
    free(map);
}