/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:49:26 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/16 15:02:25 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_dup(char **content, int lines)
{
	int	i;
	int	j;

	i = 0;
	while (content[i] && i < lines -1)
	{
		j = i +1;
		while (content[j])
		{
			if ((!ft_strncmp(content[i], content[j], ft_strlen(content[i])) \
				&& !is_map(content[i])) || \
				(!ft_strncmp(&content[i][skip_sep(content[i], 3)], \
				&content[j][skip_sep(content[j], 3)], \
				ft_strlen(&content[i][3])) && !is_map(&content[i])))
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

	tx_fd = open(&content[i][skip_sep(content, 3)], O_WRONLY);
	if (tx_fd < 0)
	{
		free_matrix(content);
		clean_exit(strerror(errno), 2);
	}
	close(tx_fd);
	return (ft_strdup(&content[skip_sep(content, 3)]));
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
	res = (ft_atoi(rgb[0]) << 16) + (ft_atoi(rgb[1]) << 8) + ft_atoi(rgb[2]);
	return (hex_str(res));
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

char	*hex_str(int res)
{
	int		i;
	int		j;
	char	*base;
	char	hex[7];

	i = 0;
	ft_bzero(hex, 7);
	base = "0123456789ABCDEF";
	while (res >= 0)
	{
		j = 0;
		while (base[j])
		{
			if (res % 10 == j)
				hex[6 - i] = base[j];
			j++;
		}
		i++;
		res / 10;
	}
	return (hex);
}
