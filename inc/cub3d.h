/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:02:09 by cbouvet           #+#    #+#             */
/*   Updated: 2024/05/13 18:03:07 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB3D_H
# define CUB3D_H

// -LIBRARIES-
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

// -MACROS-
// Errorrs
# define PARAM_NB		"Incorrect number of parameters."
# define EMPTY_PARAM	"Empty parameter."

// -STRUCTS-
// Map struct
typedef struct s_map
{
	char	**map;
	char	*north_tex;
	char	*east_tex;
	char	*west_tex;
	char	*south_tex;
	char	*floor;
	char	*ceiling;
}	t_map;
// All-encompassing struct
typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_var;

// -FUNCTIONS-
// Base
t_var	*var(void);
// Parser
void	parser(char **av);
// Data parser
void	data_parser(int fd);
// Map parser
void	map_parser(int fd);
int		map_len(char **map);
int		mapline_strlen(char *str);
int		check_borders(int i);
int		check_column(void);
int		check_up(int i, int j);
int		check_down(int i, int j);
int		check_line(void);
int		check_character(void);
int		kinda_floodfill(void);
int		check_player(void);
// Texture parser
int		get_newsfc(char *line);
int		clr_to_int(char *code);
// Display
void	display_win(void);
// Clean & exit
void	clean_exit(char *err_msg, int err_code);

#endif
