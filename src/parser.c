/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:18:35 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/17 16:06:34 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Sends to parsing functions
void	parser(char **av)
{
	int		fd;
	char	**txt;

	if (!av[1] || !av[1][0])
		clean_exit(EMPTY_PARAM, 1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		clean_exit(strerror(errno), errno);
	txt = store_mapfile(fd);
	close(fd);
	if (!txt || !txt[0])
	{
		free_matrix(txt);
		clean_exit(WRONG_DATA, 2);
	}
	check_dup(txt, get_2d_len(txt));
	map_parser(txt, data_parser(txt));
}

char	**store_mapfile(int fd)
{
	char	*buff;
	char	*join;
	char	*tmp;
	char	**txt;

	tmp = get_next_line(fd);
	while (1)
	{
		buff = get_next_line(fd);
		if (!buff)
			break;
		join = ft_strjoin(tmp, buff);
		free(tmp);
		free(buff);
		tmp = join;
		join = NULL;
	}
	txt = ft_split(tmp, '\n');
	free(tmp);
	return (txt);
}

int	data_parser(char **txt)
{
	int	i;

	i = 0;
	while (txt[i] && !tx_complete(&var()->map))
	{
		if (!ft_strncmp(txt[i], "NO ", 3) && !var()->map.ntx)
			var()->map.ntx = tx_error(txt, i);
		else if (!ft_strncmp(txt[i], "EA ", 3) && !var()->map.etx)
			var()->map.etx = tx_error(txt, i);
		else if (!ft_strncmp(txt[i], "WE ", 3) && !var()->map.wtx)
			var()->map.wtx = tx_error(txt, i);
		else if (!ft_strncmp(txt[i], "SO ", 3) && !var()->map.stx)
			var()->map.stx = tx_error(txt, i);
		else if (!ft_strncmp(txt[i], "F ", 2) && !var()->map.fhex)
			var()->map.fhex = clr_to_hex(txt, i);
		else if (!ft_strncmp(txt[i], "C ", 2) && !var()->map.chex)
			var()->map.chex = clr_to_hex(txt, i);
		else if (!is_separator(txt[i]))
			clean_exit(WRONG_DATA, 2);
		i++;
	}
	return (i);
}

void	map_parser(char **txt, int i)
{
	int		j;
	int		start;

	if (!tx_complete(&var()->map))
	{
		free_matrix(txt);
		clean_exit(WRONG_DATA, 2);
	}
	while (txt[i] && is_separator(txt[i]))
		i++;
	start = i;
	while (txt[i] && !is_separator(txt[i]))
		i++;
	var()->map.cmap = ft_calloc(i - start +1, (sizeof(char *)));
	j = 0;
	while (start < i)
		var()->map.cmap[j++] = ft_strdup(txt[start++]);
	free_matrix(txt);
	check_characters(var()->map.cmap);
}
