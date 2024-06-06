/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:49:26 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/06 18:45:12 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Checks for duplicate content (except for map)
void	check_dup(char **txt, int lines)
{
	int	i;
	int	j;
	int	itx;

	i = 0;
	while (txt[i] && i < lines -1)
	{
		j = i +1;
		itx = skip_sep(txt[i], 3);
		while (txt[j])
		{
			if ((!ft_strncmp(txt[i], txt[j], ft_strlen(txt[i]) + 1) \
			&& !is_separator(txt[i]) && !is_map(txt[i])) || \
			(!ft_strncmp(&txt[i][itx], &txt[j][skip_sep(txt[j], 3)], \
			ft_strlen(&txt[i][itx]) + 1) && !is_map(&txt[i][itx])))
			{
				free_cmatrix(txt);
				clean_exit(DUP_ERR, 2);
			}
			j++;
		}
		i++;
	}
}

// Checks if xml texture can be opened + inits texture
void	set_texture(t_tex *tex, char **txt, int i)
{
	int		tx_fd;

	tx_fd = open(&txt[i][skip_sep(txt[i], 3)], O_WRONLY);
	if (tx_fd < 0)
	{
		free_cmatrix(txt);
		clean_exit(strerror(errno), 2);
	}
	close(tx_fd);
	tex->name = ft_strdup(&txt[i][skip_sep(txt[i], 3)]);
	tex->bit_pix = sizeof(int);
	tex->img = mlx_xpm_file_to_image(var()->mlx, tex->name, &tex->width, &tex->height);
	if (!tex->img)
	{
		free_cmatrix(txt);
		clean_exit(IMG_ERR, 3);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bit_pix, &tex->line_len, &tex->endian);
	tex->pixel = malloc(sizeof(int) * tex->width * tex->height);
	if (!tex->pixel)
	{
		free_cmatrix(txt);
		clean_exit(MALLOC_ERR, 3);
	}
	ft_memcpy(tex->pixel, tex->addr, tex->width * tex->height * sizeof(int));
}

// Performs verifications on RGB values
int	clr_to_hex(char **txt, int i)
{
	int		res;
	char	**rgb;

	rgb = ft_split(&txt[i][skip_sep(txt[i], 2)], ',');
	if (!check_rgb(rgb))
	{
		free_cmatrix(txt);
		clean_exit(WRONG_DATA, 3);
	}
	res = (ft_atoi(rgb[0]) << 16) + (ft_atoi(rgb[1]) << 8) + ft_atoi(rgb[2]);
	free_cmatrix(rgb);
	return (res);
}

// Checks if RGB values are valid
int	check_rgb(char **rgb)
{
	int		i;

	i = 0;
	if (rgb == NULL || get_2d_len(rgb) != 3)
		return (0);
	while (i < 3)
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
		{
			free_cmatrix(rgb);
			return (0);
		}
		i++;
	}
	return (1);
}

// Converts RGB values into hex-format string
char	*hex_str(int res)
{
	int		i;
	int		j;
	char	*base;
	char	*hex;

	i = 0;
	hex = ft_calloc(7, sizeof(char));
	base = "0123456789ABCDEF";
	while (res > 0)
	{
		j = 0;
		while (base[j])
		{
			if (res % 16 == j)
			{
				hex[5 - i] = base[j];
				res /= 16;
				i++;
				break ;
			}
			j++;
		}
	}
	return (hex);
}
