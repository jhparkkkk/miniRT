/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_divide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:45:27 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/17 18:27:11 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vec3	vec_divide(t_vec3 v, double scalar)
{
	t_vec3	res;

	res.x = v.x / scalar;
	res.y = v.y / scalar;
	res.z = v.z / scalar;
	return (res);
}
