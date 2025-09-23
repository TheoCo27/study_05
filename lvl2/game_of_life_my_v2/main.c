/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:55:25 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/23 16:29:46 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

int main(int argc, char **argv)
{
	if (argc != 4)
		return 1;
	t_game game;
	init_game(&game);
	game.width = atoi(argv[1]);
	game.height = atoi(argv[2]);
	game.iterations = atoi(argv[3]);
	game.board = init_board(game.width, game.height);
	if(!game.board)
		return 1;
	if(get_stdin_line(&game) == 1)
		return(ft_free_all(game.board), 1);
	if (start_life(&game) == 1)
		return(ft_free_all(game.board), 1);
	ft_free_all(game.board);
}

// int main(int argc, char **argv)
// {
// 	if (argc != 4)
// 		return 1;
// 	t_game game;
// 	init_game(&game);
// 	game.cmd = get_stdin_line();
// 	game.width = atoi(argv[1]);
// 	game.height = atoi(argv[2]);
// 	game.iterations = atoi(argv[3]);
// 	game.board = init_board(game.width, game.height);
// 	ft_putmap(game.board);
// }