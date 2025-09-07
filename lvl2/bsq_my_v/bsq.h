/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:16:25 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/07 19:46:24 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BSQ_H
#define _BSQ_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/errno.h>

#define OK 1
#define KO 0

typedef struct s_map
{
	long nb_line;
	long map_width;
	long map_height;
	size_t line_length;
	char empty_c;
	char obstacle_c;
	char full_c;
	char **map;
	char *filename;
	FILE *file;
	int fline_index;
	int fline_start;

} t_map;

int ft_strlen(char *str);
void ft_strcpy(char *dest, char *src);
void free_all(char **map);
int map_len(char **map);
char **get_map(FILE *file, t_map *map);
char **copy_map(char **map, int line_count);

#endif