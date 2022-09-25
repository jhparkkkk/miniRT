/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:26:02 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/25 11:29:28 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	print_sp(t_object sp)
{
	printf("\nsphere center : %f, y : %f, z : %f\n", sp.center.x,
	sp.center.y, sp.center.z);
	printf("sphere radius %f\n", sp.radius);
	printf("sphere color : %f, y : %f, z : %f\n", sp.color.x,
	sp.color.y, sp.color.z);
	printf("\n");
}