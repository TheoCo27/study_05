/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:55:22 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/23 16:30:02 by tcohen           ###   ########.fr       */
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

void ft_free_all(char **tab)
{
	for (int i = 0; tab[i]; i++)
		ft_free(tab[i]);
	free(tab);
	tab = NULL;
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
