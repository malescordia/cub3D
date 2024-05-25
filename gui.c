/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/25 14:58:18 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

#define SCREENWIDTH 800
#define SCREENHEIGHT 800

typedef struct s_map
{
	char	*ntx;
	char	*etx;
	char	*wtx;
	char	*stx;
	char	*fhex;
	char	*chex;
	char	**cmap;
	int		**imap;
}	t_map;

typedef struct s_tex
{
	void    *img;
    char    *data;
	int		height;
	int		width;
    
	int		len;
    
    int     endian;
    int     bits; 
}   t_tex;

typedef struct s_data
{
    struct s_tex	ntx;
	struct s_tex	etx;
	struct s_tex	wtx;
	struct s_tex	stx;
    struct s_tex    render;
    struct s_map    *map;
    
    void *mlx;
}   t_data;

/* DIDNT TEST ANYTHING */
int	init_textures(t_data *data)
{
	data->ntx.img = mlx_xpm_file_to_image(data->mlx, data->map->ntx, &data->ntx.width, &data->ntx.height);
	data->etx.img = mlx_xpm_file_to_image(data->mlx, data->map->etx, &data->etx.width, &data->etx.height);
	data->wtx.img = mlx_xpm_file_to_image(data->mlx, data->map->wtx, &data->wtx.width, &data->wtx.height);
	data->stx.img = mlx_xpm_file_to_image(data->mlx, data->map->stx, &data->stx.width, &data->stx.height);
	data->render.img = mlx_new_image(data->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!data->etx.img || !data->wtx.img || !data->stx.img || !data->ntx.img || !data->render.img)
		return (1);
	data->render.data = mlx_get_data_addr(data->render.img, &data->render.bits, &data->render.len, &data->render.endian);
	data->ntx.data = mlx_get_data_addr(data->ntx.img, &data->ntx, &data->ntx.len, &data->ntx.endian);
    data->etx.data = mlx_get_data_addr(data->etx.img, &data->etx, &data->etx.len, &data->etx.endian);
	data->wtx.data = mlx_get_data_addr(data->wtx.img, &data->wtx, &data->wtx.len, &data->wtx.endian);
	data->stx.data = mlx_get_data_addr(data->stx.img, &data->stx, &data->stx.len, &data->stx.endian);
	return (0);
}

// int is_news(char c)
// {
//     if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
//         return (1);
//     return (0);
// }

// void draw_cell(void *mlx, void *win, int x, int y, int color)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i < CELL_SIZE)
//     {
//         j = 0;
//         while (j < CELL_SIZE)
//         {
//             mlx_pixel_put(mlx, win, x + j, y + i, color);
//             j++;
//         }
//         i++;
//     }
// }


// void render_map(t_disp *disp)
// {
//     int i;
//     int j;

//     i = 0;
//     while(var()->map.cmap[i])
//     {
//         j = 0;
//         while (var()->map.cmap[i][j])
//         {
//             if (var()->map.cmap[i][j] == '1')
//                 draw_cell(disp->mlx, disp->win, j * CELL_SIZE, i * CELL_SIZE, 0x00002F);
//             else if (var()->map.cmap[i][j] == '0')
//                 draw_cell(disp->mlx, disp->win, j * CELL_SIZE, i * CELL_SIZE, 0x808080);
//             else if(is_news(var()->map.cmap[i][j]))
//                 draw_cell(disp->mlx, disp->win, j * CELL_SIZE, i * CELL_SIZE, 0x00FF00);
//             else
//                 draw_cell(disp->mlx, disp->win, j * CELL_SIZE, i * CELL_SIZE, 0x000000);
//             j++;
//         }
//         i++;
//     }
// }
