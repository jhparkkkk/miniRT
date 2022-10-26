/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_nb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:58:06 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/26 15:12:40 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/* Returns 0 if there isnt the expected number of elements. Otherwise,
 returns 1*/
int	check_elements_nb(int expected, char *data)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (data[i])
	{
		jump_spaces(data, &i);
		if (data[i])
		{
			jump_data(data, &i);
			nb++;
		}
	}
	if (nb == expected)
		return (1);
	return (0);
}
