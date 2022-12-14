/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:59:14 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/28 14:41:05 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	print_cy(t_object cy)
{
	printf("\ncylinder center : %f, y : %f, z : %f\n", cy.center.x,
		cy.center.y, cy.center.z);
	printf("\ncylinder direction : %f, y : %f, z : %f\n", cy.dir.x,
		cy.dir.y, cy.dir.z);
	printf("cylinder radius %f\n", cy.radius);
	printf("cylinder hight %f\n", cy.height);
	printf("cylinder color : %f, y : %f, z : %f\n", cy.color.x,
		cy.color.y, cy.color.z);
	printf("\n");
}
