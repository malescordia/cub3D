/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:07:27 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/13 18:07:51 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	clean_exit(char *err_msg, int err_code)
{
	if (err_msg)
		fd_printf(2, "Error\n%s\n", err_msg);
	/* if (var()->map)
		free_map(var()->map); */
	exit(err_code);
}
