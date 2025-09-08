/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:19:03 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/08 15:34:31 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int ft_strlen(char *str)
{
	if (!str)
		return 0;
	int i = 0;
	while(str[i])
		i++;
	return i;
}

void ft_strcpy(char *dest, char *src)
{
	int i = 0;
	if (!dest || !src)
		return;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
void free_all(char **map)
{
	int i = 0;
	while(map[i])
	{
		if (map[i] != NULL)
		{
			free(map[i]);
			map[i] = NULL;
		}
		i++;
	}
	free(map);
}

int map_len(char **map)
{
	int i = 0;

	while(map[i])
		i++;
	return i;
}