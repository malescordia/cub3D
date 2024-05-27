/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:59:59 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/27 15:04:04 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int code)
{
	if (code == 65361)
		var()->left = true;
	else if (code == 65363)
		var()->right = true;
	else if (code == 'w' || code == 'W')
		var()->w_key = true;
	else if (code == 'a' || code == 'A')
		var()->a_key = true;
	else if (code == 's' || code == 'S')
		var()->s_key = true;
	else if (code == 'd' || code == 'D')
		var()->d_key = true;
	else if (code == 65307)
		clean_exit(NULL, 0);
	return (0);
}
