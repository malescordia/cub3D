/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:07:27 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/16 21:40:52 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	clean_exit(char *err_msg, int err_code)
{
	if (err_msg)
		fd_printf(2, "Error\n%s\n", err_msg);
	if (err_code > 1)
		free_map(&var()->map);
	exit(err_code);
}

void	free_map(t_map *map)
{
	if (map->ntx)
		free(map->ntx);
	if (map->etx)
		free(map->etx);
	if (map->wtx)
		free(map->wtx);
	if (map->stx)
		free(map->stx);
	if (map->fhex)
		free(map->fhex);
	if (map->chex)
		free(map->chex);
	if (map->cmap)
		free_matrix(map->cmap);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix)
	{
		i = 0;
		while (matrix[i])
			free(matrix[i++]);
		free(matrix);
	}
}
