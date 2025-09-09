/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:16:25 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/09 15:26:30 by theog            ###   ########.fr       */
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
	char char_set[4];
	char empty_c;
	char obstacle_c;
	char full_c;
	char **map;
	char *filename;
	FILE *file;
	int fline_index;
	int fline_start;
	int max_width;
	char *first_line;

} t_map;

int ft_strlen(char *str);
void ft_strcpy(char *dest, char *src);
void free_all(char **map);
int map_len(char **map);
char **get_map(FILE *file, t_map *map);
char **copy_map(char **map, int line_count);
void print_map(char **map);
void find_biggest_square(t_map *map, int width);
int treat_argv(char *filename);
int check_first_line(char *line, t_map *map);
int check_all_midline(char **tab_line, t_map *map);
void free_allbut1st(char **map);

#endif