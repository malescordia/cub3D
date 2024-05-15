/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:49:26 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/15 20:17:49 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_dup(char **content, int lines)
{
	int	i;
	int j;

	i = 0;
	while (content[i] && i < lines -1)
	{
		j = i +1;
		while (content[j])
		{
			if ((!ft_strncmp(content[i], content[j], ft_strlen(content[i])) \
			&& !is_map(content[i])) \
			|| (!ft_strncmp(&content[i][skip_sep(content[i], 3)], &content[j][skip_sep(content[j], 3)], ft_strlen(&content[i][3])) \
			&& !is_map(&content[i])))
			{
				free_matrix(content);
				clean_exit(DUP_ERR, 2);
			}
			j++;
		}
		i++;
	}
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
	return (ft_strdup(&content[3]));
}

char	*clr_to_hex(char **content, int i)
{
	int		i;
	int		res;
	char	**rgb;

	i = skip_sep(content, 2);
	rgb = split(&content[i], ',');
	if (!check_rgb(rgb))
	{
		free_matrix(content);
		clean_exit(WRONG_DATA, 3);
	}
	// calculations
	while (i < 3)
	{
		res = ft_atoi(rgb[i]) / 16;
	}
}

/* NOT TESTED YET */
/* checks numerical and unsigned char scope
	still need to check if ceiling/floor are diff */
int	check_rgb(char **rgb)
{
	int		i;

	i = 0;
	if (rgb == NULL || get_2d_len(rgb != 3))
			return (0);
	while (i < 3)
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
