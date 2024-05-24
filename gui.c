/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/19 14:39:26 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int is_news(char c)
{
    if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
        return (1);
    return (0);
}

void draw_cell(void *mlx, void *win, int x, int y, int color)
{
    int i;
    int j;
    
    i = 0;
    while (i < CELL_SIZE)
    {
        j = 0;
        while (j < CELL_SIZE)
        {
            mlx_pixel_put(mlx, win, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

void render_map(t_var *data)
{
    int i;
    int j;
    
    i = 0;
    while(data->map.cmap[i])
    {
        j = 0;
        while (data->map.cmap[i][j])
        {
            if (data->map.cmap[i][j] == '1')
                draw_cell(data->mlx, data->win, j * CELL_SIZE, i * CELL_SIZE, 0x00002F);
            else if (data->map.cmap[i][j] == '0')
                draw_cell(data->mlx, data->win, j * CELL_SIZE, i * CELL_SIZE, 0x808080);
            else if(is_news(data->map.cmap[i][j]))
                draw_cell(data->mlx, data->win, j * CELL_SIZE, i * CELL_SIZE, 0x00FF00);
            else
                draw_cell(data->mlx, data->win, j * CELL_SIZE, i * CELL_SIZE, 0x000000);
            j++;
        }
        i++;
    }
}