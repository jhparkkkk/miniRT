/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:34:12 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/26 11:39:24 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_vec3 get_normal(t_object *cap, t_vec3 dir)
{
	double dot_in;
	double dot_out;
	t_vec3		normal_in; //orientation
	t_vec3		normal_out; //orientation

	normal_in = cap->direction;
	normal_out = vec_scalar(cap->direction, -1.0);
	dot_in = vec_dot(normal_in, dir);
	dot_out = vec_dot(normal_out, dir);
	if (dot_in < dot_out)
		return (normal_out);
	return (normal_in);
}

t_hit_point	hit_cap(t_ray *ray, t_object *cap, double shadow)
{
	t_vec3		normal; //orientation
	t_vec3		distance_from_origin; //position
	double		denom;
	t_hit_point hit;

	(void)shadow;
	hit.status = 0;
	distance_from_origin = vec_substract(cap->center, ray->origin);
	normal = get_normal(cap, ray->direction); // cap direction est normalisé dans le create cap
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
