/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:17:26 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/09 15:29:42 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int check_set_only(char *str, char *set)
{
	int i = 0;
	int check = 0;
	while(str[i])
	{
		int j = 0;
		check = 0;
		while(set[j])
		{
			if (set[j] == str[i])
			{
				check = 1;
				break;
			}
			j++;
		}
		if (check == 0 && str[i] != '\n' && i != (ft_strlen(str) - 1))
			return 0;
		i++;
	}
	return (1);
}

int ft_isdigit(char c)
{
	int check = (int)c; 
	if (check < 48 || check > 57)
		return 0;
	return 1;
}

int check_midline(char *line, t_map *map)
{
	int last_char;
	if (check_set_only(line, map->char_set) == 0)
		return 0;
	if (ft_strlen(line) < 1)
		return 0;
	if (line == map->map[map->map_height - 1])
	{
		if (ft_strlen(line) != map->map_width - 1)
			return 0;
		
		return 1;
	}
	if (ft_strlen(line) != map->map_width)
		return 0;
	last_char = ft_strlen(line) - 1;
	if (line[last_char] != '\n')
		return 0;
	return 1;
}

int check_all_midline(char **tab_line, t_map *map)
{
	printf("in allmidline func\n");
	int i = 0;
	while(tab_line[i])
	{
		if (check_midline(tab_line[i], map) == 0)
			return 0;
		i++;
	}
	if (i == 0)
		return 0;
	fprintf(stdout, "all midline validated\n");
	return 1;
}

int check_first_line(char *line, t_map *map)
{
	int i = 0;
	int nb_ok = 0;
	int empty_ok = 0;
	int wall_ok = 0;
	int full_ok = 0;

	while(line[i] )
	{
		if (nb_ok == 0 && ft_isdigit(line[i]) == 0)
			return 0;
		if (nb_ok == 0 && ft_isdigit(line[i]) == 1)
			nb_ok = 1;
		if (nb_ok == 1 && ft_isdigit(line[i]) == 0 && line[i] != ' ')
			return 0;
		if (nb_ok == 1 && ft_isdigit(line[i]) == 0 && line[i] == ' ')
			break;
		i++;
	}
	char *char_set = &line[i];
	if (ft_strlen(char_set) != 7)
		return 0;
	char s1 = char_set[0];
	char empty = char_set[1];
	char s2 = char_set[2];
	char wall = char_set[3];
	char s3 = char_set[4];
	char full = char_set[5];
	char lbreak = char_set[6];
	if (empty == wall || empty == full || wall == full)
		return 0;
	if (empty == '\n' || full == '\n' || wall == '\n')
		return 0;
	if (s1 != ' ' || s2 != ' ' || s3 != ' ')
		return 0;
	if (lbreak != '\n')
		return 0;
	//check printable_char
	map->char_set[0] = empty;
	map->char_set[1] = wall;
	map->char_set[2] = full;
	map->char_set[3] = '\0';
	return 1;
}