/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 15:19:03 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/06 15:30:31 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

void ft_strcpy(char *dest, char *src)
{
	int i = 0;

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
}

int map_len(char **map)
{
	int i = 0;

	while(map[i])
		i++;
	return i;
}