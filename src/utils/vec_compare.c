/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:33:47 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/25 19:45:58 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/*Returns 0 if v1 and v2 are the same. Returns 1 if they are different*/
int	vec_compare(t_vec3 v1, t_vec3 v2)
{
	if (!(fabs(v1.x - v2.x) < __DBL_EPSILON__)
		|| !(fabs(v1.y - v2.y) < __DBL_EPSILON__)
		|| !(fabs(v1.z - v2.z) < __DBL_EPSILON__))
		return (1);
	return (0);
}
