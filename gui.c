/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbouvet <cbouvet@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/15 19:32:18 by cbouvet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

////////////////////////////////////////////////////////////////////////////////////////
//                                    UTILS                                           //
//                               all functions tested                                 //
////////////////////////////////////////////////////////////////////////////////////////

/* returns map length */
int	get_2d_len(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
		i++;
	return (i);
}

/* return length until end of str or '\n' is found */
int	strlen_until_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

/* receives a line and in order to find out if there is anything is not a '1', ' ' or '\n'
    return 0 if all is gud
	return -1 if condition is not ok */
int	check_borders(t_map *map, int i)
{
	int	j;

	j = 0;
	while (map->cmap[i][j])
	{
		if (map->cmap[i][j] != '1' && map->cmap[i][j] != ' ' && map->cmap[i][j] != '\n')
			return (printf("FREEING STUFF == CAMI'S PART ✨"), -1);
		j++;
	}
	return (0);
}

/* check the indexes above given coordinate (same column)
	return 0 if a '1' is found
	return -1 if a space or edge of map is reached before a '1' */
int	check_up(t_map *map, int i, int j)
{
	while (i > 0)
	{
		if (map->map[i - 1][j] && map->map[i - 1][j] == '1')
			return (0);
		if (map->map[i - 1][j] && map->map[i - 1][j] == ' ')
			return (-1);
		i--;
	}
	return (-1);
}

/* check the indexes bellow given coordinate (same column)
	return 0 if a '1' is found
	return -1 if a space or edge of map is reached before a '1' */
int	check_down(t_map *map, int i, int j)
{
	while (i < get_2d_len(map->map))
	{
		if (map->map[i + 1][j] && map->map[i + 1][j] == '1')
			return (0);
		if (map->map[i + 1][j] && map->map[i + 1][j] == ' ')
			return (-1);
		i++;
	}
	return (-1);
}

////////////////////////////////////////////////////////////////////////////////////////
//                           WHERE IT ALL BEGINS                                      //
//    use check_character to iterate through all the parsing functions                //
//                          all functions tested                                      //
////////////////////////////////////////////////////////////////////////////////////////

/* check if map only contains valid characters
    return -1 otherwise */
int	check_characters(char **map)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = " NEWSFC\n";
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && ft_strchr(str,
					map[i][j]) == 0)
				return (printf("FREEING STUFF == CAMI'S PART ✨"), -1);
			j++;
		}
		i++;
	}
	return (check_line(map));
}

/* check each line to ensure it starts and ends with '1'
	return -1 is this condition is not ok */
int	check_line(char **map)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (map[i])
	{
		start = 0;
		end = ft_strlen(map[i]) - 1;
		while (map[i][start] == ' ')
			start++;
		while (map[i][end] == ' ' || map[i][end] == '\n')
			end--;
		if (map[i][start] != '1' || map[i][end] != '1')
			return (printf("FREEING STUFF == CAMI'S PART ✨"), -1);
		i++;
	}
	return (check_column(map));
}

/* check if each '0' has a '1' above or bellow it
    a loop iterates down to check up
    another loop iterates up to check down *IM A GENIUS*
	return -1 if this condition is not ok */
int	check_column(char **map)
{
	int	j;
	int	start;
	int	end;

	start = 0;
	end = get_2d_len(map) - 1;
	if (check_borders(map, start) == -1 || check_borders(map, end) == -1)
		return (printf("FREEING STUFF == CAMI'S PART ✨"), -1);
	while (map[start] && start <= end)
	{
		j = 1;
		while (map[start][j])
        {
			if (map[start][j] == '0' && check_up(map, start, j) == -1)
				return (printf("FREEING STUFF == CAMI'S PART ✨"), -1);
            j++;
        }
		start++;
	}
	while (end >= 0 && map[end])
	{
		j = 1;
		while (map[end][j])
        {
			if (map[end][j] == '0' && check_down(map, end, j) == -1)
				return (printf("FREEING STUFF == CAMI'S PART ✨"), -1);
            j++;
        }
		end--;
	}
	return (kinda_floodfill(map));
}

/* check that every '0' and every 'NEWS' is surrounded by 'N', 'E', 'W', 'S', 1' or '0'
	return -1 if the '0' is not surrounded in this way */
int	kinda_floodfill(char **map)
{
	int		i;
	int		j;
	char	*str;

	str = "NEWS01";
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || ft_strchr("NEWS", map[i][j]))
			{
				if (j + 1 > strlen_until_newline(map[i - 1])
					|| j + 1 > strlen_until_newline(map[i + 1])
					|| ft_strchr(str, map[i - 1][j]) == 0
					|| ft_strchr(str, map[i + 1][j]) == 0
					|| ft_strchr(str, map[i][j - 1]) == 0
					|| ft_strchr(str, map[i][j + 1]) == 0)
					return (printf("FREEING STUFF == CAMI'S PART ✨"), -1);
			}
			j++;
		}
        i++;
	}
	return (check_player(map));
}

/* checks for player existence
	returns -1 if multiple players or no player */
int check_player(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NEWS", map[i][j]))
			{
				if (player == 1)
					return (printf("FREEING STUFF == CAMI'S PART ✨"), -1);
				player = 1;
			}
			j++;
		}
		i++;
	}
	if (player == 0)
		return (printf("FREEING STUFF == CAMI'S PART ✨"), -1);
    return (0);
}

////////////////////////////////////////////////////////////////////////////////////////
//                           TEXTURES AND COLORS                                      //
//                               not perfect                                          //
////////////////////////////////////////////////////////////////////////////////////////

/* NOT TESTED YET */
/* function should be inserted inside a while loop that iterates through the first lines of the file (CAMI'S PART ✨) */
int	get_newsfc(t_map *map, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
    // need to include a function here to check if tex / color code has already been saved
    // since this is in a loop it would get us an infinite loop, Im tired to do it now
	if (!ft_strncmp(split[0], "NO", 2) && !map->ntx && !split[2] && ft_strlen(split[0]) == 2)
		map->ntx = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "EA", 2) && !map->etx && !split[2] && ft_strlen(split[0]) == 2)
		map->etx = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "WE", 2) && !map->wtx && !split[2] && ft_strlen(split[0]) == 2)
		map->wtx = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "SO", 2) && !map->stx && !split[2] && ft_strlen(split[0]) == 2)
		map->stx = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "F", 1) && !map->ftx && !split[2] && ft_strlen(split[0]) == 1)
		map->ftx = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "C", 1) && !map->ctx && !split[2] && ft_strlen(split[0]) == 1)
		map->ctx = ft_strdup(split[1]);
	return (("FREEING THE SPLIT == CAMI'S PART ✨"), 0);
}

/* NOT TESTED YET */
int	clr_to_int(char *code)
{
    int n;

    n = ft_atoi(code);
    return (n);
}

////////////////////////////////////////////////////////////////////////////////////////
//                           DISPLAY A WINDOW                                         //
////////////////////////////////////////////////////////////////////////////////////////

/* tested */
int display_win(void)
{
	t_var data;

	data.mlx = mlx_init();
	if(!data.mlx)
		return (printf("FREEING STUFF == CAMI'S PART ✨"), -1);
	data.win = mlx_new_window(data.mlx, 1680, 1680, "cub3D");
	if(!data.win)
		return (printf("FREEING STUFF == CAMI'S PART ✨"), -1);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 17, 1L << 17, mlx_loop_end, data.mlx); // for X and minimizing
	mlx_loop(data.mlx);
	return(printf("display_win success!\n"), 0);
}

////////////////////////////////////////////////////////////////////////////////////////
//                                 HOOKS                                              //
////////////////////////////////////////////////////////////////////////////////////////
/* tested */
int key_press(int code, t_var *data)
{
    if (code == 65361)
        printf("Left arrow key pressed\n");
    else if (code == 65362)
        printf("Up arrow key pressed\n");
    else if (code == 65363)
        printf("Right arrow key pressed\n");
    else if (code == 65364)
        printf("Down arrow key pressed\n");
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
    return(printf("key_press success!\n"), 0);
}

////////////////////////////////////////////////////////////////////////////////////////
//                        FLOOR / CEILING ERROR CHECKING                              //
////////////////////////////////////////////////////////////////////////////////////////

/* NOT TESTED YET */
/* checks numerical and unsigned char scope
	still need to check if ceiling/floor are diff */
int	check_rgb(char *content)
{
	int		i;
	char	**rgb;

	i = 0;
	rgb = ft_split(content, ',');
	if (rgb == NULL || get_2d_len(rgb != 3))
			return (0);
	while (i < 3)
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0)
			return (0);
		i++;
	}
	return (1)
}

/* function to convert rgd to hexa */
