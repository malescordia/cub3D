/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-cas <gude-cas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:15:01 by gude-cas          #+#    #+#             */
/*   Updated: 2024/05/05 17:46:23 by gude-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/* returns length of the file */
int get_file_length(char *file)
{
    int i;
    int fd;
    char *tmp;

    i = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
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

/* convert file content to array of strings */
char **create_matrix(char *file, int size, char **content)
{
    int i;
    int fd;
    char *tmp;
    
    i = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        return (fd_printf(2, "Error\n"), perror(file), NULL);
    content = malloc(sizeof(char *) * (size + 1));
    if (!content)
        return (NULL);
    while (size > 0)
    {
        tmp = get_next_line(fd);
        content[i] = ft_strdup(tmp);
        i++;
        size--; // can be shortened if lines needed
        free(tmp);
    }
    content[i] = NULL;
    close(fd);
    return (content);
}

int parser(char *file)
{
    int size;
    t_map *map;
    
    size = get_file_length(file);
    map = malloc(sizeof(t_map)); // consider calloc
    if (size == -1)
        return (free_map(map), -1);
    map->content = create_matrix(file, size, map->content);
    if (!map->content)
        return (free_map(map), -1);
        
    print_map(map->content); // <---- tester

    return (0);
}