/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:18:35 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/14 18:09:20 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Sends to parsing functions
void	parser(char **av)
{
	int		i;
	int		fd;
	int		lines;
	char	**content;

	if (!av[1] || !av[1][0])
		clean_exit(EMPTY_PARAM, 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		clean_exit(strerror(errno), errno);
	i = 0;
	lines = get_line_nb(fd);
	*content = malloc(sizeof(char *) * (lines +1));
	if (!content)
		clean_exit(MALLOC_ERR, 3);
	content[lines] = NULL;
	while (!EOF && i < lines)
		content[i++] = ft_strdup(get_next_line(fd));
	close(fd);
	check_dup(content);
	data_parser(content);
	map_parser(content);
}


