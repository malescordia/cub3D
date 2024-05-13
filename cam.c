/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:04 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/13 21:48:53 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void	data_parser(int fd)
{
	char	*buff;

	buff = calloc(100, sizeof(char));
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
