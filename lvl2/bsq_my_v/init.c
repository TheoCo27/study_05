/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:48:27 by theog             #+#    #+#             */
/*   Updated: 2025/09/09 15:42:18 by theog            ###   ########.fr       */
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
    map->map = malloc(sizeof(char *) * 2);
    map->filename = NULL;
    map->file = NULL;
	map->fline_index = -1;
    map->fline_start = -1;
	map->max_width = 0;
    map->first_line = NULL;
}


// int treat_argv(char *filename)
// {
//     fprintf(stdout, "Filename is %s\n", filename);
//     t_map map_instack;
//     t_map *map = &map_instack;
//     char **tmp_map = NULL;
//     char *tmp_line1 = NULL;
//     init_map(map);
//     map->filename = filename;
//     map->file = fopen(filename, "r");
//     if (!map->file)
//     {
//         fprintf(stderr, "Error: Cannot open file %s\n", filename);
//         return 1;
//     }
//     if (get_map(map->file, map) == NULL)
//         return -1;
//     //checker_functions here
//     print_map(map->map);
//     free_all(map->map);
//     free(tmp_line1);
//     return 0;
// }

int treat_argv(char *filename)
{
    t_map map_instack;
    t_map *map = &map_instack;
    char **tmp_map = NULL;
    char *tmp_line1 = NULL;
    init_map(map);
    if (!map->map)
        return 1;
    map->filename = filename;
    map->file = fopen(filename, "r");
    if (!map->file)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return 1;
    }
    if (get_map(map->file, map) == NULL)
        return -1;
    tmp_map = map->map;
    tmp_line1 = map->map[0];
    map->first_line = map->map[0];
    map->map_height = map_len(map->map) - 1;
    map->map_width = ft_strlen(map->map[1]);
    if (check_first_line(tmp_line1, map) == 0)
        return(free_all(tmp_map), 1);
    if (map_len(map->map) < 2)
        return(free_all(tmp_map), 1);
    map->map = &map->map[1];
    if (check_all_midline(map->map, map) == 0)
        return(free_all(tmp_map), 1);
    map->empty_c = map->char_set[0];
    map->obstacle_c = map->char_set[1];
    map->full_c = map->char_set[2];
    fprintf(stdout, "\n charset = %s\n", map->char_set);
    if (map->map_height <= map->map_width)
        map->max_width = map->map_height;
    else if(map->map_width < map->map_height)
        map->max_width = map->map_width;
    find_biggest_square(map, map->max_width);
    //free(tmp_line1);
    free_all(tmp_map);
    printf("\n%p\n", (void *)map->char_set);
    return 0;
}