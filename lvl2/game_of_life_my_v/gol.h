/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:55:29 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/22 22:59:23 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GOL_H_
# define _GOL_H_

#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"

typedef struct s_game
{
	char *cmd;
	int width;
	int height;
	int iterations;
	char **board;
	int pen_line_nb;
	int pen_index;
	int pen_writting;

}t_game;


int ft_strlen(char* str);
void ft_strcpy(char *src, char *dst);
void ft_free(void *ptr);
char *ft_str_append(char *base, char *to_add);
char *get_stdin_line(void);
void init_game(t_game *board);
void ft_free_all(void **tab);
void fill_with_space(char *str, int len);
char **init_board(int width, int height);
void ft_putstr(char *str);
void ft_putmap(char **map);
void start_life(t_game *game);

#endif