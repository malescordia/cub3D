/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:59:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/19 12:57:30 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int code, t_var *data)
{
	if (code == 65361)
		printf("Left arrow key pressed\n");
	else if (code == 65363)
		printf("Right arrow key pressed\n");
	else if (code == 'w' || code == 'W')
		printf("W key pressed\n");
	else if (code == 'a' || code == 'A')
		printf("A key pressed\n");
	else if (code == 's' || code == 'S')
		printf("S key pressed\n");
	else if (code == 'd' || code == 'D')
		printf("D key pressed\n");
	else if (code == 65307)
		mlx_loop_end(data->mlx);
	return (0);
}
