/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/06/06 16:21:10 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

/* FUNCTION THAT GIVES ACCESS TO ALL OTHERS
    render the entire screen by raycasting for each column. */
/* void    draw(void)
{
    int x;

    x = 0;
    while (x < WIDTH)
    {
        var()->cam = 2 * x / (double)WIDTH - 1;
        var()->ray_dir[0] = var()->dir[0] + var()->player.plane_cor[0] * var()->cam;
        var()->ray_dir[1] = var()->dir[1] + var()->player.plane_cor[1] * var()->cam;
        before_dda();
        dda();
        var()->line_heigth = (int)(HEIGHT / var()->perp_wall_dist);
        var()->draw_start = -var()->line_heigth / 2 + HEIGHT / 2;
        if (var()->draw_start < 0)
            var()->draw_start = 0;
        var()->draw_end = var()->line_heigth / 2 + HEIGHT / 2;
        if (var()->draw_end >= HEIGHT)
            var()->draw_end = HEIGHT - 1;
        if (var()->side == 0)
            var()->wall_point = var()->player.pos[1] + var()->perp_wall_dist \
                * var()->ray_dir[1];
        else
            var()->wall_point = var()->player.pos[0] + var()->perp_wall_dist \
                * var()->ray_dir[0];
        var()->wall_point -= floor(var()->wall_point);
        draw_image(x, var()->draw_start, var()->draw_end);
        x++;
    }
} */

/* ugly way to initialize textures */
/* int init_textures(t_map *map)
{
    map->n_wall.img = mlx_xpm_file_to_image(var()->mlx, map->ntx, \
        &map->n_wall.width, &map->n_wall.height);
    map->e_wall.img = mlx_xpm_file_to_image(var()->mlx, map->etx, \
        &map->e_wall.width, &map->e_wall.height);
    map->w_wall.img = mlx_xpm_file_to_image(var()->mlx, map->wtx, \
        &map->w_wall.width, &map->w_wall.height);
    map->s_wall.img = mlx_xpm_file_to_image(var()->mlx, map->stx, \
        &map->s_wall.width, &map->s_wall.height);
    map->render.img = mlx_new_image(var()->mlx, WIDTH, HEIGHT);
    if (!map->n_wall.img || !map->e_wall.img || !map->w_wall.img || \
        !map->s_wall.img || !map->render.img)
        clean_exit(IMG_ERR, 3);
    map->render.addr = (unsigned int *)mlx_get_data_addr(map->render.img, \
        &map->render.bit_pix, &map->render.line_len, &map->render.endian);
    map->n_wall.addr = (unsigned int *)mlx_get_data_addr(map->n_wall.img, \
        &map->n_wall.bit_pix, &map->n_wall.line_len, &map->n_wall.endian);
    map->e_wall.addr = (unsigned int *)mlx_get_data_addr(map->e_wall.img, \
        &map->e_wall.bit_pix, &map->e_wall.line_len, &map->e_wall.endian);
    map->w_wall.addr = (unsigned int *)mlx_get_data_addr(map->w_wall.img, \
        &map->w_wall.bit_pix, &map->w_wall.line_len, &map->w_wall.endian);
    map->s_wall.addr = (unsigned int *)mlx_get_data_addr(map->s_wall.img, \
        &map->s_wall.bit_pix, &map->s_wall.line_len, &map->s_wall.endian);
    return (0);
} */

/* helper for 'load_all_textures' */
void    load_texture(void *mlx, t_tex *tex, char *path)
{
    tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
    if (!tex->img)
        clean_exit(IMG_ERR, 3);
    tex->addr = (unsigned int *)mlx_get_data_addr(tex->img, \
        &tex->bit_pix, &tex->line_len, &tex->endian);
}

/* pretty way to initialize textures */
void    load_all_textures(void *mlx, t_tex textures[4])
{
    load_texture(mlx, &textures[0], "textures/blue.xpm");
    load_texture(mlx, &textures[1], "textures/grey.xpm");
    load_texture(mlx, &textures[2], "textures/yellow.xpm");
    load_texture(mlx, &textures[3], "textures/red.xpm");
}

/* prepares variables for dda implementation, it calculates the initial side distances
    and step directions based on the ray direction */
/* void    before_dda(void)
{
    var()->map_pos[0] = (int)var()->player.pos[0];
    var()->map_pos[1] = (int)var()->player.pos[1];
    var()->delta_dist[0] = fabs(1 / var()->ray_dir[0]);
    var()->delta_dist[1] = fabs(1 / var()->ray_dir[1]);
    if (var()->ray_dir[0] < 0)
    {
        var()->step[0] = -1;
        var()->side_dist[0] = (var()->player.pos[0] - var()->map_pos[0]) \
            * var()->delta_dist[0];
    }
    else
    {
        var()->step[0] = 1;
        var()->side_dist[0] = (var()->map_pos[0] + 1.0 - var()->player.pos[0]) \
            * var()->delta_dist[0];
    }
    if (var()->ray_dir[1] < 0)
    {
        var()->step[1] = -1;
        var()->side_dist[1]= (var()->player.pos[1] - var()->map_pos[1]) \
            * var()->delta_dist[1];
    }
    else
    {
        var()->step[1] = 1;
        var()->side_dist[1]= (var()->map_pos[1] + 1.0 - var()->player.pos[1]) \
            * var()->delta_dist[1];
    }
} */

/* perform the algorithm to detect collisions with walls. It iterates through the grid,
    updating side distances and map positions until a collision is detected. It then
    calculates the perpendicular wall distance based on which side of the wall was hit. */
/* void	dda(void)
{
	var()->collision = 0;
	while (var()->collision == 0)
	{
		if (var()->side_dist[0] < var()->side_dist[1])
		{
			var()->side_dist[0] += var()->delta_dist[0];
			var()->map_pos[0] += var()->step[0];
			var()->side = 0;
		}
		else
		{
			var()->side_dist[1] += var()->delta_dist[1];
			var()->map_pos[1] += var()->step[1];
			var()->side = 1;
		}
		if (var()->map.imap[var()->map_pos[0]][var()->map_pos[1]] > 0)
			var()->collision = 1;
	}
	if (var()->side == 0)
		var()->perp_wall_dist = (var()->side_dist[0] - var()->delta_dist[0]);
	else
		var()->perp_wall_dist = (var()->side_dist[1] - var()->delta_dist[1]);
} */

/* determines which texture to use based on the side of the wall hit and the ray direction.
    It also calculates the texture coordinate(tex_point) to use for rendering the wall. */
t_tex   get_texture(void)
{
    t_tex current;

    if (var()->side == 0 && var()->ray_dir[0] < 0)
        current = var()->map.n_wall;
    else if (var()->side == 1 && var()->ray_dir[1] > 0)
        current = var()->map.e_wall;
    else if (var()->side == 1 && var()->ray_dir[1] < 0)
        current = var()->map.w_wall;
    else
        current = var()->map.s_wall;
    var()->tex_point = (int)var()->wall_point * (double)(current.width);
    if (var()->side == 0 && var()->ray_dir[0] > 0)
        var()->tex_point = current.width - var()->tex_point - 1;
    if (var()->side == 1 && var()->ray_dir[1] < 0)
        var()->tex_point = current.width - var()->tex_point - 1;
    return (current);
}

/* draws a vertical stripe of the wall at column 'x' from 'start' to 'end' on the screen.
    It also draws the ceiling and floor colors. */
void    draw_image(int x, int start, int end)
{
    t_tex   current;
    int y;
    int tex_y;
    double step;
    double tex_pos;

    y = 0;
    current = get_texture();
    step = 1.0 * current.height / var()->line_heigth;
    tex_pos = (start - HEIGHT / 2 + var()->line_heigth / 2) * step;
    while (y < start)
    {
        var()->map.render.addr[y * var()->map.render.line_len / 4 + x] = var()->map.ceiling;
        y++;
    }
    y = start - 1;
    while (y <= end)
    {
        tex_y = (int)tex_pos & (current.height - 1);
        tex_pos += step;
        var()->clr = current.addr[tex_y * current.line_len / 4 + var()->tex_point];
        var()->map.render.addr[y * var()->map.render.line_len / 4 + x] = var()->clr;
        y++;
    }
    y = end;
    while (y < HEIGHT)
    {
        var()->map.render.addr[y * var()->map.render.line_len / 4 + x] = var()->map.floor;
        y++;
    }
}
