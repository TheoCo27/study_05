/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:48:27 by theog             #+#    #+#             */
/*   Updated: 2025/09/07 19:09:34 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void init_map(t_map *map)
{
    map->nb_line = 0;
    map->map_width = 0;
    map->map_height = 0;
    map->line_length = 0;
    map->empty_c = '\0';
    map->obstacle_c = '\0';
    map->full_c = '\0';
    map->map = NULL;
    map->filename = NULL;
    map->file = NULL;
}

int treat_argv1(t_map *map, char *filename)
{
    init_map(map);
    map->filename = filename;
    map->file = fopen(filename, "r");
    if (!map->file)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return 1;
    }
    if (get_map(map->file, map) == NULL)
        return -1;
    else 
        return 0;
}