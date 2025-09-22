/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:00:35 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/22 23:17:02 by theog            ###   ########.fr       */
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
			return (ft_free_all((void **)board), NULL);
		board[i][width] = '\0';
		fill_with_space(board[i], width);
	}
	return board;
}


char *get_stdin_line(void)
{
	char buffer[501];

	buffer[0] = '\0';

	char *line = malloc(sizeof(char));
	if (!line)
		return NULL;
	line[0] = '\0';
	int read_check = 0;

	while((read_check = read(0, buffer, 500)) > 0)
	{
		if (read_check <= 0)
			break;
		buffer[read_check] = '\0';
		line = ft_str_append(line, buffer);
		if (!line)
			return NULL;
	}
	if (read_check < 0)
		return (ft_free(line), NULL);
	return line;
}