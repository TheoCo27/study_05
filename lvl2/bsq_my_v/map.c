/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:33:57 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/09 15:43:53 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void print_map(char **map)
{
	int i = 0;
	
	while(map[i])
	{
		fprintf(stdout, "%s", map[i]);
		i++;
	}
	
}

char **copy_map(char **map, int line_count)
{
	int i = 0;

	char **map_copy;

	map_copy = malloc((sizeof(char *) * (line_count + 1)));
	if (!map_copy)
		return (NULL);
	while(map[i])
	{
		map_copy[i] = malloc((sizeof(char) * (ft_strlen(map[i]) + 1)));
		if (!map_copy[i])
			return(free_all(map_copy), NULL);
		ft_strcpy(map_copy[i], map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

char **add_line_to_map(char *line, char **map, int line_count)
{
	if (!line)
		return(free_all(map), NULL);
	char **map_copy = NULL;

	map_copy = map;
	map = malloc((sizeof(char *)) * (line_count + 1));
	if (!map)
		return(free_all(map), NULL);
	map[line_count] = NULL;
	int i = 0;
	while(map_copy != NULL && map_copy[i])
	{
		map[i] = map_copy[i];
		i++;
	}
	map[i] = line;
	free(map_copy);
	return (map);
}

char **get_map(FILE *file, t_map *map)
{
	char *line = NULL;
	errno = 0;
	int line_count = 0;
	size_t len = 0;      // taille du buffer (sera gérée par getline)
    ssize_t nread;       // nombre de caractères lus

	while((nread = getline(&line, &len, file)) != -1)
	{
		line_count++;
		if ((map->map = add_line_to_map(line, map->map, line_count)) == NULL)
			return (NULL);
		len = 0;
		line = NULL;
	}
	free(line);
	if (errno == 0)
		return (fclose(file), map->map);
	else
		return(fclose(file), free_all(map->map), NULL);
}