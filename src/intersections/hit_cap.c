/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:34:12 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/23 14:50:05 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_hit_point	hit_cap(t_ray *ray, t_object *cap)
{
	t_vec3		normal; //orientation
	t_vec3		distance_from_origin; //position
	double		denom;
	t_hit_point hit;

	hit.status = 0;
	normal = cap->direction; // cap direction est normalisé dans le create cap
	distance_from_origin = vec_substract(cap->center, ray->origin);
	denom = vec_dot(normal, ray->direction);
	if (denom > __DBL_EPSILON__) // si proche de 0 c'est parallele
	{
		hit.root = vec_dot(distance_from_origin, normal) / denom;
		if (hit.root >= __DBL_EPSILON__)
		{
			hit.point = vec_add(ray->origin, vec_scalar(ray->direction, hit.root));
			t_vec3 center_to_point = vec_substract(hit.point, cap->center);
			double distance_center_to_point = sqrt(vec_dot(center_to_point, center_to_point));
			if (distance_center_to_point < cap->radius)
			{
				hit.status = 1;
			}
			return (hit);
		}
	}
	return (hit);
}
