/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:07 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/16 18:45:06 by cbouvet          ###   ########.fr       */
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
}
