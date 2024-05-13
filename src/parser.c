/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:18:35 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/13 21:38:09 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Sends to parsing functions
void	parser(char **av)
{
	int	fd;

	if (!av[1] || !av[1][0])
		clean_exit(EMPTY_PARAM, 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		clean_exit(strerror(errno), errno);
	data_parser(fd);
	/* map_parser(fd); */
}


