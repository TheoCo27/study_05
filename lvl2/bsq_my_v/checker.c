/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:17:26 by tcohen            #+#    #+#             */
/*   Updated: 2025/09/06 15:19:57 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int check_set_only(char *str, char *set)
{
	int i = 0;
	int check = 0;
	while(str[i])
	{
		int j = 0;
		check = 0;
		while(set[j])
		{
			if (set[j] == str[i])
			{
				check = 1;
				break;
			}
			j++;
		}
		if (check = 0)
			return 0;
		i++;
	}
	return (1);
}