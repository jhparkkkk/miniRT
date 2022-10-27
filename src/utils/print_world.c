/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:19:38 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/27 13:18:26 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	print_world(t_view **view)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZEX)
	{
		j = 0;
		while (j < SIZEY)
		{
			printf("%.f;%.f ", view[i][j].dot.x, view[i][j].dot.y);
			j++;
		}
		printf("\n");
		i++;
	}
}
