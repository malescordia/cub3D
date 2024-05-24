/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:07:27 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/24 16:43:44 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Prints error message + frees variables + exits
void	clean_exit(char *err_msg, int err_code)
{
	if (err_msg)
		fd_printf(2, "Error\n%s\n", err_msg);
	if (err_code != 1)
		free_map(&var()->map);
	exit(err_code);
}

// Frees map components
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
	if (map->imap)
		free_imatrix(map->imap, get_2d_len(map->cmap));
	if (map->cmap)
		free_cmatrix(map->cmap);
}

// Frees matrix of ints
void	free_imatrix(int **matrix, int indexes)
{
	int	i;

	i = 0;
	while (i < indexes)
	{
		if (matrix[i])
			free(matrix[i]);
		i++;
	}
	free(matrix);
}

// Frees matrix of chars
void	free_cmatrix(char **matrix)
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
