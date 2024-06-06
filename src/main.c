/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:07 by cbouvet           #+#    #+#             */
/*   Updated: 2024/06/06 14:30:35 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Static struct containing all useful variables
t_var	*var(void)
{
	static t_var	var;

	return (&var);
}

// Main
int	main(int ac, char **av)
{
	if (ac != 2)
		clean_exit(PARAM_NB, 1);
	parser(av);
	init_player(var()->map.cmap);
	//init_display(&var()->disp_2d, 0, "cub2d");
	init_display(&var()->disp_3d, 1, "cub3d");
	if (var()->disp_2d.win)
		cub2d_maker(var()->map.cmap);
	//camera_plane(&var()->player);
	cub3d_maker(&var()->player);

	mlx_loop_hook(var()->mlx, hooks_handler, NULL);
	mlx_loop(var()->mlx);
	clean_exit(NULL, 0);
}

// Prints various tests
void	print_tests(void)
{
	int	i;
	int	j;

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
	printf("\n");
	printf("\n");
	printf("Player pos: %f - %f\n", var()->player.pos[0], var()->player.pos[1]);
	printf("player facing: %f\n", var()->player.dir);
	//printf("camera plane: %f\n", var()->player.plane);
}
