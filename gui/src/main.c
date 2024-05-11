/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:25:24 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/11 12:49:19 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int main(int ac, char **av)
{
	(void)ac;
    if(parser(av[1]) == -1)
        return (0);
    return (0);
}

int parser(char *file)
{
    int size;
    t_map *map;

    size = get_file_length(file);
    map = malloc(sizeof(t_map));
    if (size == -1)
        return (free_map(map), -1);
    map->content = create_matrix(file, size, map->content);
    if (!map->content)
        return (free_map(map), -1);
	// TO CONTINUE
}

char **create_matrix(char *file, int size, char **content)
{
    int i;
    int fd;
    char *tmp;

    i = 0;
    fd = open(file, O_RDONLY);
    if(fd == -1)
        return (fd_printf(2, "Error\n"), perror(file), NULL);
    content = malloc(sizeof(char *) * (size + 1));
    if (!content)
        return (fd_printf(2, "Error\nMalloc failed\n"), NULL);
    while (size > 0)
    {
        tmp = get_next_line(fd);
        content[i] = ft_strdup(tmp);
        i++;
        size--;
        free(tmp);
    }
    content[i] = NULL;
    close(fd);
    return (content);
}

int get_file_length(char *file)
{
    int i;
    int fd;
    char *tmp;

    i = 0;
    fd = open(file, O_RDONLY);
    if(fd == -1)
        return (fd_printf(2, "Error\n"), perror(file), -1);
    tmp = get_next_line(fd);
    while (tmp)
    {
        free(tmp);
        i++;
        tmp = get_next_line(fd);
    }
    close(fd);
    return (i);
}

void free_map(t_map *map)
{
    free_matrix(map->content);
    free(map);
}

void free_matrix(char **matrix)
{
    int i;

    i = 0;
    while (matrix && matrix[i])
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
}