/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:26:02 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/11 14:26:48 by cgosseli         ###   ########.fr       */
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
	if (sp.surface == SHINY)
		printf("sphere type : SHINY\n");
	else
		printf("sphere type : MAT\n");
	printf("sphere specular exponent : %f\n", sp.specular_exponent);
	printf("sphere k_spec : %f\n", sp.k_spec);
	printf("\n");
}