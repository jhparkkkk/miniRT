/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:32:41 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/27 13:18:39 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	print_pl(t_object pl)
{
	printf("\nplane position : x : %f, y : %f, z : %f\n", pl.center.x,
		pl.center.y, pl.center.z);
	printf("plane orientation : x : %f, y : %f, z : %f\n", pl.dir.x,
		pl.dir.y, pl.dir.z);
	printf("plane color : %f, y : %f, z : %f\n", pl.color.x,
		pl.color.y, pl.color.z);
	printf("\n");
}
