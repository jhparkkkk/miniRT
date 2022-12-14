/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:59:14 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/28 14:41:09 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	print_cap(t_object cap)
{
	printf("\ncap center : %f, y : %f, z : %f\n", cap.center.x,
		cap.center.y, cap.center.z);
	printf("\ncap direction : %f, y : %f, z : %f\n", cap.dir.x,
		cap.dir.y, cap.dir.z);
	printf("cap radius %f\n", cap.radius);
	printf("cap color : %f, y : %f, z : %f\n", cap.color.x,
		cap.color.y, cap.color.z);
	printf("\n");
}
