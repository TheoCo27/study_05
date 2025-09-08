/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theog <theog@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:11:10 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/08 14:46:50 by theog            ###   ########.fr       */
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
		treat_argv(argv[1]);
		fprintf(stdout, "\n\n");
		i++;
	}
	return 0;
}