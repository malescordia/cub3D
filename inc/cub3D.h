/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:27:56 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/05 18:32:28 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct s_map
{
    char **map;
    char **content;
    
    char *north; // store path_to_the_north_texture
    char *south; // store path_to_the_south_texture
    char *west;  // store path_to_the_west_texture
    char *east;  // path_to_the_east_texture
    
    char *floor;   // store floor RGB (will need to conver to INT)
    char *ceiling; // store ceiling RGB (will need to conver to INT)
    
}   t_map;

typedef struct s_data
{
    void *mlx;
    void *win;
    
    struct s_map *map;
    
}   t_data;

/* parse */
int parser(char *file);

/* free */
void free_map(t_map *map);

/* TESTERS */
void print_map(char **map);

#endif