/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:57:15 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/23 16:26:47 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

int check_w(t_game *game)
{
	if (game->pen_line_nb == 0)
		return 0;
	return 1;
}

int check_a(t_game *game)
{
	if (game->pen_index == 0)
		return 0;
	return 1;
}

int check_s(t_game *game)
{
	if (game->pen_line_nb == game->height - 1)
		return 0;
	return 1;
}

int check_d(t_game *game)
{
	if (game->pen_index == game->width - 1)
		return 0;
	return 1;
}

int check_if_valid_cmd(char c, t_game *game)
{
	if (c != 'w' && c != 'a' && c!= 's' && c != 'd' && c!= 'x')
		return 0;
	if (c == 'w')
		return (check_w(game));
	else if (c == 'a')
		return (check_a(game));	
	else if (c == 's')
		return (check_s(game));	
	else if (c == 'd')
		return (check_d(game));	
	return 1;
}

void write_if_necessary(t_game *game)
{
	if (game->pen_writting == 0)
		return;
	game->board[game->pen_line_nb][game->pen_index] = '0';
}

void switch_pen_status(t_game *game)
{
	if(game->pen_writting == 0)
	{
		game->pen_writting = 1;
		write_if_necessary(game);
	}
	else
		game->pen_writting = 0;
}


void make_move(char c, t_game *game)
{
	if (check_if_valid_cmd(c, game) == 0)
		return;
	if (c == 'x')
	{
		switch_pen_status(game);
		return;
	}
	else if (c == 'w')
		game->pen_line_nb--;
	else if (c == 'a')
		game->pen_index--;
	else if (c == 's')
		game->pen_line_nb++;
	else if (c == 'd')
		game->pen_index++;
	write_if_necessary(game);
}

int check_if_overflow(int j, int i, int it_j, int it_i, t_game *board)
{
	if ((it_j + j) < 0 || (it_j + j) == board->height)
		return 1;
	if((it_i + i) < 0 || (it_i + i) == board->width)
		return 1;
	return 0;
}

int get_nb_neighboors(int i, int j, t_game *game)
{
	int nb_neighboors = 0;

	for(int it_j = -1; it_j <= 1; it_j++)
	{
		for(int it_i = -1; it_i <= 1; it_i++)
		{
			if(it_i == 0 && it_j == 0)
				continue;
			if(check_if_overflow(j, i, it_j, it_i, game) == 0 && game->board[it_j + j][it_i + i] == '0')
				nb_neighboors++;
		}
	}
	return nb_neighboors;
}

int is_alive(char alive, int nb_neighboors)
{
	if (alive == '0')
	{
		if (nb_neighboors < 2)
			return 0;
		if (nb_neighboors >= 2 && nb_neighboors <= 3)
			return 1;
		if (nb_neighboors > 3)
			return 0;
	}
	else
	{
		if(nb_neighboors == 3)
			return 1;
		return 0;
	}
}

int play_life(t_game *game)
{
	int j = 0;
	char **new_board = init_board(game->width, game->height);
	if (!new_board)
		return(1);
	while(game->board[j])
	{
		int i = 0;
		while(game->board[j][i])
		{
			int nb_neighboors = 0;
			nb_neighboors = get_nb_neighboors(i, j, game);
			if (is_alive(game->board[j][i], nb_neighboors) == 1)
				new_board[j][i] = '0';
			i++;
		}
		j++;
	}
	char **temp = game->board;
	game->board = new_board;
	ft_free_all(temp);
	return 0;
}

int start_life(t_game *game)
{
	int i = 0;
	while(i < game->iterations)
	{
		if (play_life(game) == 1)
			return 1;
		i++;
	}
	ft_putmap(game->board);
	return 0;
}
