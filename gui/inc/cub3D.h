/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:27:56 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/11 12:47:45 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// -LIBRARIES-
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

// -MACROS-

// -STRUCTS-
typedef struct s_map
{
    char **content;
}   t_map;

// -FUNCTIONS-
int parser(char *file);
void free_map(t_map *map);
int get_file_length(char *file);
void free_matrix(char **matrix);
char **create_matrix(char *file, int size, char **content);

#endif
