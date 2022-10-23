/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_btm_cap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:59:14 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/23 13:41:31 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	print_cap(t_object cap)
{
	printf("\ncap center : %f, y : %f, z : %f\n", cap.center.x,
	cap.center.y, cap.center.z);
	printf("\ncap direction : %f, y : %f, z : %f\n", cap.direction.x,
	cap.direction.y, cap.direction.z);
	printf("cap radius %f\n", cap.radius);
	printf("cap color : %f, y : %f, z : %f\n", cap.color.x,
	cap.color.y, cap.color.z);
	if (cap.surface == SHINY)
		printf("cap type : SHINY\n");
	else
		printf("cap type : MAT\n");
	printf("\n");
}