/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:55:22 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/22 17:32:05 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void fill_with_space(char *str, int len)
{
	for (int i = 0; i < len; i++)
		str[i] = ' ';
}

void init_game(t_game *board)
{
	board->cmd = NULL;
	board->height = 0;
	board->width = 0;
	board->iterations = 0;
	board->board = NULL;
	board->pen_index = 0;
	board->pen_line_nb = 0;
	board->pen_writting = 0;
}

void ft_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void ft_free_all(void **tab)
{
	for (int i = 0; tab[i]; i++)
		ft_free(tab[i]);
	free(tab);
	tab = NULL;
}

int ft_strlen(char* str)
{
	if (!str)
		return 0;
	int i = 0;
	while(str[i])
		i++;
	return i;
}

void ft_strcpy(char *src, char *dst)
{
	if (!src || !dst)
		return;
	int i = 0;
	while(src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char *ft_str_append(char *base, char *to_add)
{
	char *output = NULL;
	int output_len = ft_strlen(base) + ft_strlen(to_add);

	output = malloc(sizeof(char) * (output_len + 1));
	if(!output)
		return (ft_free(base), NULL);
	ft_strcpy(base, output);
	if (base)
		ft_free(base);
	ft_strcpy(to_add, &output[ft_strlen(output)]);
	return output;
}

void ft_putstr(char *str)
{
	for(int i = 0; str[i]; i++)
		putchar((int)str[i]);
}

void ft_putmap(char **map)
{
	for(int i = 0; map[i]; i++)
	{
		ft_putstr(map[i]);
		putchar('\n');
	}
}

