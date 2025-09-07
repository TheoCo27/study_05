/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:26:13 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/07 19:45:43 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int possible_1stline(char *line, char wall, int width, int start)
{
    int i = start;
    int wall_check = 0;
    int available_len = 0;
    while(line[i])
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
        if (line[i] == NULL)
            return -1;
        else
            possible_line(line, wall, width, (i + 1));
    }
    return -1;
}

int possible_line(char *line, char wall, int width, int start)
{
    int i = start;
    int available_len = 0;
    while(line[i])
    {
        if (line[i] == wall)
            return -1;
        available_len++;
        if (available_len == width)
            return start;
        i++;
    }
    return -1;
}

int find_square(t_map map, int width)
{
    int j = 0;
    int i = 0;
    int first_line_found = 0;
    int first_line_index = 0;
    int first_line_start = 0;
    int check_midline = 0;

    while(map.map[j])
    {
        if (first_line_found == 0)
        {
            first_line_start = possible_1stline(map.map[j], map.obstacle_c, width, first_line_start);
            if (first_line_start != -1)
            {
                first_line_found = 1;
                j++;
                continue;
            }
        }
        if (possible_line(map.map[j], map.obstacle_c, width, first_line_start) == -1)
        {
            j = 0;
            first_line_found = 0;
            first_line_start++;
            continue;
        }
        check_midline++;
        if (check_midline == width - 1)
            return 1;
        j++;
    }
    
}
