/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:59:14 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/19 14:01:16 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	print_cy(t_object cy)
{
	printf("\ncylinder center : %f, y : %f, z : %f\n", cy.center.x,
	cy.center.y, cy.center.z);
	printf("\ncylinder direction : %f, y : %f, z : %f\n", cy.direction.x,
	cy.direction.y, cy.direction.z);
	printf("cylinder radius %f\n", cy.radius);
	printf("cylinder hight %f\n", cy.height);
	printf("cylinder color : %f, y : %f, z : %f\n", cy.color.x,
	cy.color.y, cy.color.z);
	if (cy.surface == SHINY)
		printf("sphere type : SHINY\n");
	else
		printf("sphere type : MAT\n");
	printf("\n");
}