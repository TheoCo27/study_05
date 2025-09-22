/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:57:15 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/22 20:02:23 by tcohen           ###   ########.fr       */
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

void init_life(t_game *game)
{
	int i = 0;
	while(game->cmd[i])
	{
		make_move(game->cmd[i], game);
		i++;
	}
}

int get_nb_neighboors(int index, int line_nb, t_game *game)
{
	int i = index;
	int j = line_nb;
	int nb_neighboors = 0;

	if (game->board[j][i + 1] == '0')
		nb_neighboors++;
	if (game->board[j + 1][i] == '0')
		nb_neighboors++;
	if (game->board[j + 1][i + 1] == '0')
		nb_neighboors++;
	if (game->board[j - 1][i - 1] == '0')
		nb_neighboors++;


	return nb_neighboors;
}

void play_life(t_game *game)
{

}