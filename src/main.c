/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:07 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/17 12:04:18 by gude-cas         ###   ########.fr       */
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
	printf("NORTH: %s\n", var()->map.ntx);
	printf("EAST: %s\n", var()->map.etx);
	printf("WEST: %s\n", var()->map.wtx);
	printf("SOUTH: %s\n", var()->map.stx);
	printf("\nFLOOR: %s\n", var()->map.fhex);
	printf("CEILING: %s\n\n", var()->map.chex);
	i = 0;
	while (var()->map.cmap[i])
		printf("> %s\n", var()->map.cmap[i++]);
}
