/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:07 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/24 15:47:57 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_var	*var(void)
{
	static t_var	var;

	return (&var);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		clean_exit(PARAM_NB, 1);
	parser(av);
	init_player(var()->map.cmap);

	print_tests();

	clean_exit(NULL, 0);
}

void	print_tests(void)
{
	int	i;

	printf("NORTH: %s\n", var()->map.ntx);
	printf("EAST: %s\n", var()->map.etx);
	printf("WEST: %s\n", var()->map.wtx);
	printf("SOUTH: %s\n", var()->map.stx);
	printf("\nFLOOR: %s\n", var()->map.fhex);
	printf("CEILING: %s\n\n", var()->map.chex);
	i = 0;
	while (var()->map.cmap[i])
	{
		printf("%i	%s\n", i, var()->map.cmap[i]);
		i++;
	}
	i = 0;
	int j;
	printf("\n");
	while (var()->map.cmap[i])
	{
		j = 0;
		printf("%i	", i);
		while (var()->map.cmap[i][j])
		{
			if (var()->map.imap[i][j] >= 0)
				printf("%i", var()->map.imap[i][j]);
			else
				printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	printf("Player pos: %f - %f\n", var()->player.pos[0], var()->player.pos[1]);
	printf("player facing: %f - %f\n", var()->player.dir[0], var()->player.dir[1]);
	printf("camera plane: %f - %f\n", var()->player.plane[0], var()->player.plane[1]);
	printf("FOV: %f\n", var()->player.fov);
}
