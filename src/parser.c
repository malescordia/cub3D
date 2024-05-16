/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:18:35 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/16 21:52:21 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Sends to parsing functions
void	parser(char **av)
{
	int		i;
	int		fd;
	int		lines;
	char	**txt;

	if (!av[1] || !av[1][0])
		clean_exit(EMPTY_PARAM, 1);
	i = 0;
	lines = get_line_nb(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		clean_exit(strerror(errno), errno);
	txt = ft_calloc(lines, sizeof(char *));
	while (i < lines)
	{
		txt[i] = get_next_line(fd);
		txt[i][ft_strlen(txt[i]) -1] = 0;
		i++;
	}
	close(fd);
	check_dup(txt, lines);
	i = data_parser(txt);
	map_parser(txt, i);
}

int	data_parser(char **txt)
{
	int	i;

	i = 0;
	while (txt[i] && !tx_complete(&var()->map))
	{
		if (!ft_strncmp(txt[i], "NO ", 3) && !var()->map.ntx)
			var()->map.ntx = tx_err(txt, i);
		else if (!ft_strncmp(txt[i], "EA ", 3) && !var()->map.etx)
			var()->map.etx = tx_err(txt, i);
		else if (!ft_strncmp(txt[i], "WE ", 3) && !var()->map.wtx)
			var()->map.wtx = tx_err(txt, i);
		else if (!ft_strncmp(txt[i], "SO ", 3) && !var()->map.stx)
			var()->map.stx = tx_err(txt, i);
		else if (!ft_strncmp(txt[i], "F ", 2) && !var()->map.fhex)
			var()->map.fhex = clr_to_hex(txt, i);
		else if (!ft_strncmp(txt[i], "C ", 2) && !var()->map.chex)
			var()->map.chex = clr_to_hex(txt, i);
		else if (!is_separator(txt[i]))
			clean_exit(WRONG_DATA, 2);
		i++;
	}
	if (!tx_complete(&var()->map))
	{
		free_matrix(txt);
		clean_exit(WRONG_DATA, 2);
	}
	return (i);
}

void	map_parser(char **txt, int i)
{
	int		j;
	int		start;

	while (txt[i] && is_separator(txt[i]))
		i++;
	start = i;
	while (txt[i] && !is_separator(txt[i]))
		i++;
	var()->map.cmap = malloc(sizeof(char *) * (i-start+1));
	if (!var()->map.cmap)
		clean_exit(MALLOC_ERR, 4);
	j = 0;
	while (start < i)
		var()->map.cmap[j++] = ft_strdup(txt[start++]);
	free_matrix(txt);
	check_characters(var()->map.cmap);
}


