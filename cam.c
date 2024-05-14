/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/14 18:09:44 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	get_line_nb(int fd)
{
	int		lines;

	lines = 0;
	while (!EOF)
	{
		get_next_line(fd);
		lines++;
	}
	return (lines);
}

void	check_dup(char **content)
{

}

void	data_parser(char **content)
{
	int	i;

	i = 0;
	while (content[i] && !tx_complete(var()->map))
	{
		if (!ft_strnmp(content[i], "NO ", 3))
			var()->map->stx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "EA ", 3))
			var()->map->etx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "WE ", 3))
			var()->map->wtx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "SO ", 3))
			var()->map->stx = tx_err(content, i);
		else if (!ft_strncmp(content[i], "F ", i))
			var()->map->ftx = clr_to_hex(content);
		else if (!ft_strncmp(content[i], "C ", i))
			var()->map->ctx = clr_to_hex(content);
		else if (!is_separator(content[i]))
			clean_exit(WRONG_DATA, 2);
		i++;
	}
}


int	tx_complete(t_map *map)
{
	if (!map->ntx || !map->etx || !map->wtx || !map->stx || !map->ftx || !map->ctx)
		return (0);
	return (1);
}

char	*tx_err(char **content, int i)
{
	int	tx_fd;

	tx_fd = open(&content[i][3], O_WRONLY);
	if (tx_fd < 0)
	{
		free_matrix(content);
		clean_exit(strerror(errno), 2);
	}
	close(tx_fd);
	return (ft_strdup(&buff[3]));
}

int	is_separator(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] < 9 || buff[i] > 13 || buff != " ")
			return (0);
		i++;
	}
	return (1);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix)
	{
		while(matrix[i])
			free(matrix[i++]);
		free(matrix);
	}
}
