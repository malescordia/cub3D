/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/04/24 14:57:24 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/* return 0 if file extension is correct */
int	check_file_extension(char *filename)
{
	char	*ext;

	ext = ft_strchr(filename, '.');
	if (ext)
	{
		if (ft_strncmp(ext, ".cub", 5) == 0)
			return (0);
	}
	return (1);
}

void init_data(t_data *data)
{
    data->win = NULL;
}

int main(int ac, char **av) 
{
    t_data data;
    
    if (ac == 2)
    {
        init_data(&data);
        if (check_file_extension(av[1]) == 1)
        {
            ft_putstr_fd("Error\n", 2);
            ft_putstr_fd("File extension must be \".cub\"\n", 2);
        }
    }
    else
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("Usage: ./cub3D <path_to_map>\n", 2);
    }
    return (0);
}
