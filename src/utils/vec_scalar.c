/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_scalar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:38:25 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/25 19:30:42 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vec3	vec_scalar(t_vec3 v1, double scalar)
{
	t_vec3	v2;

	v2.x = v1.x * scalar;
	v2.y = v1.y * scalar;
	v2.z = v1.z * scalar;
	return (v2);
}
