/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:07:27 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/06 16:58:55 by cbouvet          ###   ########.fr       */
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
	if (var()->disp_2d.win)
		free_display(&var()->disp_2d);
	if (var()->disp_3d.win)
		free_display(&var()->disp_3d);
	if (var()->mlx)
	{
		mlx_destroy_display(var()->mlx);
		mlx_loop_end(var()->mlx);
		free(var()->mlx);
	}
	exit(err_code);
}

// Frees map components
void	free_map(t_map *map)
{
	if (map->ntx.name)
		free(map->ntx.name);
	if (map->etx.name)
		free(map->etx.name);
	if (map->wtx.name)
		free(map->wtx.name);
	if (map->stx.name)
		free(map->stx.name);
	if (map->cmap)
		free_cmatrix(map->cmap);
	if (map->ntx.img)
		mlx_destroy_image(var()->mlx, map->ntx.img);
	if (map->etx.img)
		mlx_destroy_image(var()->mlx, map->etx.img);
	if (map->wtx.img)
		mlx_destroy_image(var()->mlx, map->wtx.img);
	if (map->stx.img)
		mlx_destroy_image(var()->mlx, map->stx.img);
}

// Frees disp struct contents
void	free_display(t_disp *disp)
{
	if (disp->img)
		mlx_destroy_image(var()->mlx, disp->img);
	if (disp->win)
	{
		mlx_clear_window(var()->mlx, disp->win);
		mlx_destroy_window(var()->mlx, disp->win);
	}
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
