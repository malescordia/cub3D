/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:27:56 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/03 19:38:17 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# include <math.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

typedef struct s_img
{
    int height;
    int width;
}   t_img;

typedef struct s_player
{
    float x;
    float y;    
}   t_player;

typedef struct s_ray
{
    float x;
    float y;
}   t_ray;

typedef struct s_data
{
    void *mlx;
    void *mlx_win;
    char **map;
    t_img image;
    t_ray ray;
    t_player player;
}   t_data;

#endif