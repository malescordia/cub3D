/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:18:35 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/15 20:10:08 by cbouvet          ###   ########.fr       */
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
	*content = ft_calloc(lines +1, sizeof(char *));
	while (!EOF && i < lines)
		content[i++] = ft_strdup(get_next_line(fd));
	close(fd);
	i = data_parser(content, lines);
	map_parser(content, i);
}

int	data_parser(char **content, int lines)
{
	int	i;

	i = 0;
	check_dup(content, lines);
	while (content[i] && !tx_complete(var()->map))
	{
		if (!ft_strnmp(content[i], "NO ", 3) && !var()->map->ntx)
			var()->map->ntx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "EA ", 3) && !var()->map->etx)
			var()->map->etx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "WE ", 3) && !var()->map->wtx)
			var()->map->wtx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "SO ", 3) && !var()->map->stx)
			var()->map->stx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "F ", i) && !var()->map->fhex)
			var()->map->fhex = clr_to_hex(content, i);
		else if (!ft_strncmp(content[i], "C ", i) && !var()->map->chex)
			var()->map->chex = clr_to_hex(content, i);
		else if (!is_separator(content[i]))
			clean_exit(WRONG_DATA, 2);
		i++;
	}
	return (i);
}

void	map_parser(char **content, int i)
{
	int		j;
	int		start;

	start = i;
	while (is_separator(content[start]))
		start++;
	while (!is_separator(content[i]))
		i++;
	var()->map->cmap = ft_calloc(i-start+1, sizeof(char *));
	j = 0;
	while (start < i)
		var()->map->cmap[j++] = ft_strdup(content[start++]);
	free_matrix(content);
	check_characters(var()->map->cmap);
}


