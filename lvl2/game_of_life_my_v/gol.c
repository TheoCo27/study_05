/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:57:15 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/22 23:22:25 by theog            ###   ########.fr       */
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

	if ((i != game->width - 1) && game->board[j][i + 1] == '0')
		nb_neighboors++;
	if ((j != game->height - 1) && game->board[j + 1][i] == '0')
		nb_neighboors++;
	if ((i != game->width - 1) && (j != game->height - 1) && game->board[j + 1][i + 1] == '0')
		nb_neighboors++;
	if (i != 0 && j != 0 && game->board[j - 1][i - 1] == '0')
		nb_neighboors++;
	if (j != 0 && game->board[j - 1][i] == '0')
		nb_neighboors++;
	if (i != 0 && game->board[j][i - 1] == '0')
		nb_neighboors++;
	if (j != 0 && (i != game->width - 1) && game->board[j - 1][i + 1] == '0')
		nb_neighboors++;
	if (i != 0 && (j != game->height - 1) && game->board[j + 1][i - 1] == '0')
		nb_neighboors++;

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
		else
			return 0;

	}
	return 0;
}

void play_life(t_game *game)
{
	int j = 0;
	while(game->board[j])
	{
		int i = 0;
		while(game->board[j][i])
		{
			int nb_neighboors = 0;
			nb_neighboors = get_nb_neighboors(i, j, game);
			if (is_alive(game->board[j][i], nb_neighboors) == 1)
				game->board[j][i] = '0';
			else
				game->board[j][i] = ' ';
			i++;
		}
		j++;
	}

}

void start_life(t_game *game)
{
	//ft_putstr("Empty map\n\n");
	//ft_putmap(game->board);
	init_life(game);

	int i = 0;
	//ft_putstr("Before iteration\n\n");
	//ft_putmap(game->board);
	while(i < game->iterations)
	{
		play_life(game);
		//ft_putstr("After one iteration\n\n");
		ft_putmap(game->board);
		i++;
	}
	//ft_putstr("After all iterations\n\n");
	ft_putmap(game->board);
}