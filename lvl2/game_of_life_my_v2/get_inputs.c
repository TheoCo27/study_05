/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:00:35 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/23 02:01:08 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

char **init_board(int width, int height)
{
	char **board = NULL;

	board = malloc((sizeof(char *) * (height + 1)));
	if (!board)
		return NULL;
	board[height] = NULL;
	for (int i = 0; i < height; i++)
	{
		board[i] = malloc(sizeof(char) * (width + 1));
		if (!board[i])
			return (ft_free_all(board), NULL);
		board[i][width] = '\0';
		fill_with_space(board[i], width);
	}
	return board;
}

int get_stdin_line(t_game *game)
{
	char buffer;

	int read_check = 0;

	while((read_check = read(0, &buffer, 1)) > 0)
	{
		if (read_check <= 0)
			break;
		make_move(buffer, game);
	}
	if (read_check < 0)
		return 1;
	return 0;
}