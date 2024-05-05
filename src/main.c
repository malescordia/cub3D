/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/05 17:44:29 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int main(int ac, char **av) 
{
	if (ac != 2)
		return (fd_printf(2, "Error\nInvalid number of arguments\n"), 0);
	if (ft_strlen(av[1]) < 5 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4))
		return (fd_printf(2, "Error\nMap extension must be '.cub'\n"), 0);
	if (parser(av[1]) == -1)
		return (0);
	return (0);
}

/* TESTERS */

void print_map(char **map)
{
	int i = 0;
	while(map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}