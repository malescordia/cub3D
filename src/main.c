/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/04/24 15:29:55 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/* return 0 if file extension is correct */
int	check_file_extension(char *filename)
{
	char	*extension;

	extension = ft_strchr(filename, '.');
	if (extension)
	{
		if (ft_strncmp(extension, ".cub", 5) == 0)
			return (0);
	}
	return (1);
}

int main(int ac, char **av) 
{
    (void)ac;
    (void)av;
    
    
    return (0);
}
