/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:26:13 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/09 15:15:24 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int possible_1stline(char *line, char wall, int width, int start)
{
    int i = start;
    int wall_check = 0;
    int available_len = 0;
    while(line[i] && line[i] != '\n')
    {
        if (line[i] == wall)
        {
            wall_check = 1;
            break;
        }
        available_len++;
        if (available_len == width)
            return start;
        i++;
    }
    if (wall_check == 1)
    {
        if (line[i + 1] == '\0')
            return -1;
        else
            return (possible_1stline(line, wall, width, (i + 1)));
    }
    return -1;
}

int possible_line(char *line, char wall, int width, int start)
{
    int i = start;
    int available_len = 0;
    while(line[i] && line[i] != '\n')
    {
        if (line[i] == wall)
            return i;
        available_len++;
        if (available_len == width)
            return -1;
        i++;
    }

    return i;
}

int find_square(t_map *map, int width)
{
    int j = 0;
    int i = 0;
    int first_line_found = 0;
    int first_line_index = 0;
    int first_line_start = 0;
    int wall_pos = 0;
    int midline = 0;

    while(map->map[j])
    {
        if (first_line_found == 0)
        {
            first_line_start = possible_1stline(map->map[j], map->obstacle_c, width, first_line_start);
            if (first_line_start != -1)
            {
                first_line_found = 1;
                first_line_index = j;
                j++;
                continue;
            }
            j++;
            continue;
        }
        if ((wall_pos = possible_line(map->map[j], map->obstacle_c, width, first_line_start)) != -1)
        {
            j = 0;
            first_line_found = 0;
            midline = 0;
            first_line_start = wall_pos + 1;
            continue;
        }
        midline++;
        if (midline == width - 1)
        {
            map->fline_index = first_line_index;
            map->fline_start = first_line_start;
            return 1;
        }
        j++;
    }
    return 0;
}

void add_square(t_map *map, char c, int size)
{
    int j = map->fline_index;
    int i;
    int len = 0;
    
    while(j < size)
    {
        i = map->fline_start;
        while(len < map->max_width)
        {
            if (map->map[j][i] != map->obstacle_c)
                map->map[j][i] = c;
            i++;
            len++;
        }
        len = 0;
        j++;
    }
    
}

void find_biggest_square(t_map *map, int width)
{
    int i = width;
    int square_found = 0; 
    
    while(i > 0)
    {
        if (find_square(map, i) == 1)
        {
            square_found = 1;
            break;
        }
        i--;
    }
    if(square_found == 0)
    {
        fprintf(stderr, "Error: no solution\n");
        //free_all(map->map);
        return;
    }
    add_square(map, map->full_c, i);
    print_map(map->map);
    //free_all(map->map);
}

