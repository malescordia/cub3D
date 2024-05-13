/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:27:56 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/13 17:01:33 by cbouvet          ###   ########.fr       */
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
    char **map; // extracted map from file content

    char *north_tex;
    char *east_tex;
    char *west_tex;
    char *south_tex;

    char *floor;
    char *ceiling;

}   t_map;

typedef struct s_data
{
    void *mlx;
    void *win;

}   t_data;

// -FUNCTIONS-
//Error checker
void    err_check(ac, av);
int	get_map_len(char **map);
int	strlen_until_newline(char *str);
int	check_borders(t_map *map, int i);
int	check_up(t_map *map, int i, int j);
int	check_down(t_map *map, int i, int j);
int	check_caracters(t_map *map);
int	check_line(t_map *map);
int	check_column(t_map *map);
int	kinda_floodfill(t_map *map);
int check_player(t_map *map);

int	get_newsfc(t_map *map, char *line);
int convert_color_to_int(char *code);

void display_window(t_map *map);

#endif
