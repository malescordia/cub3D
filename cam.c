/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/14 17:54:15 by cbouvet          ###   ########.fr       */
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

void	data_parser(int fd)
{
	char	*buff;

	buff = ft_calloc(100, sizeof(char));
	while (!tx_complete(var()->map) && !EOF)
	{
		buff = get_next_line(fd);
		if (!ft_strncmp(buff, "NO ", 3))
			var()->map->stx = tx_err(buff, fd);
		else if (!ft_strncmp(buff, "EA ", 3))
			var()->map->etx = tx_err(buff, fd);
		else if (!ft_strncmp(buff, "WE ", 3))
			var()->map->wtx = tx_err(buff, fd);
		else if (!ft_strncmp(buff, "SO ", 3))
			var()->map->stx = tx_err(buff, fd);
		else if (!ft_strncmp(buff, "F ", 2))
			var()->map->ftx = clr_to_hex(&buff[2]);
		else if (!ft_strncmp(buff, "C ", 2))
			var()->map->ctx = clr_to_hex(&buff[2]);
		else if (!is_separator(buff))
			clean_exit(WRONG_DATA, 2);
		ft_bzero(buff, 100);
	}
	free(buff);
	if (EOF)
	{
		close(fd);
		clean_exit(WRONG_DATA, 2);
	}
}

void	data_parser(int fd, int lines)
{
	int		i;
	char	**buff;

	i = 0;
	*buff = malloc(sizeof(char *) * (lines +1));
	if (!buff)
		clean_exit(MALLOC_ERR, 3);
	buff[lines] = NULL;
	while (!EOF && i < lines)
		buff[i++] = ft_strdup(get_next_line(fd));
}


int	tx_complete(t_map *map)
{
	if (!map->ntx || !map->etx || !map->wtx || !map->stx || !map->ftx || !map->ctx)
		return (0);
	return (1);
}

char	*tx_err(char *buff, int fd)
{
	int	tx_fd;

	tx_fd = open(&buff[3], O_WRONLY);
	if (tx_fd < 0)
	{
		free(buff);
		close(fd);
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
