/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:55:25 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/22 17:31:51 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

int main(int argc, char **argv)
{
	if (argc != 4)
		return 1;
	t_game game;
	init_game(&game);
	game.cmd = get_stdin_line();
	game.width = atoi(argv[1]);
	game.height = atoi(argv[2]);
	game.iterations = atoi(argv[3]);
//	printf("width = %d, height = %d, iterations = %d\n", game.width, game.height, game.iterations);
	game.board = init_board(game.width, game.height);
	play_the_game(&game);
	ft_putmap(game.board);
	ft_free_all((void **)game.board);
	ft_free(game.cmd);
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