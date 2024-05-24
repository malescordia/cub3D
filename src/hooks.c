/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:59:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/24 21:25:42 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int code)
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
		clean_exit(NULL, 0);
	return (0);
}
