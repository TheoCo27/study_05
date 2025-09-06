/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:33:57 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/06 15:24:48 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

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
	return (map_copy);
}

char **add_line_to_map(char *line, char **map, int line_count)
{
	if (!line)
		return(free_all(map), NULL);
	map = malloc((sizeof(char *)) * (line_count + 1));
}

char **get_map(int fd, t_map map)
{
	char *line = NULL;
	int line_count = 0;

	while(1)
	{
		line = getline(fd);
		if (!line)
			break;
		line_count++;
	}

}