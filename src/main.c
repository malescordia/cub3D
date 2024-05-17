/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:07 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/17 18:35:55 by cbouvet          ###   ########.fr       */
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
	int	i;

	if (ac != 2)
		clean_exit(PARAM_NB, 1);
	parser(av);
	place_player(var()->map.cmap);

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
	printf("Player facing: %f.%f\n", var()->player.facing_deg[0], var()->player.facing_deg[1]);
	printf("player x: %f | player y: %f\n", var()->player.xpos, var()->player.ypos);
	clean_exit(NULL, 0);
}
