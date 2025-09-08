/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:11:10 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/08 13:41:05 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"


int main(int argc, char **argv)
{
	t_map map;
	if (argc != 2)
	{
		fprintf(stderr, "%s\n", "./a.out map_file");
		return 1;
	}
	treat_argv(argv[1]);
	return 0;
}