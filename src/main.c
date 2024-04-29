/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/04/29 19:40:35 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/* return 0 if file extension is correct */
int	check_file_extension(char *filename)
{
	char	*extension;

	extension = ft_strchr(filename, '.');
	if (extension)
	{
		if (ft_strncmp(extension, ".cub", 5) == 0)
			return (0);
	}
	return (1);
}

int close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

int main(int ac, char **av) 
{
	(void)ac;
	(void)av;
	t_data data;
	
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 640, 480, "cub3D");
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	
	return (0);
}