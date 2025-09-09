/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:11:10 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/09 16:01:21 by theog            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_map map;
	int i = 1;
	while(argv[i])
	{
		fprintf(stdout, "solution for file %s\n\n", argv[1]);
		treat_argv(argv[i]);
		fprintf(stdout, "\n\n");
		i++;
	}
	if (i == 1)
		treat_stdin();
	return 0;
}