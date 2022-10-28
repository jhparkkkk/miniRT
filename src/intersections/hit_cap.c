/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:34:12 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/28 14:32:36 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_vec3	get_normal(t_object *cap, t_vec3 dir)
{
	double		dot_in;
	double		dot_out;
	t_vec3		normal_in;
	t_vec3		normal_out;

	normal_in = cap->dir;
	normal_out = vec_scalar(cap->dir, -1.0);
	dot_in = vec_dot(normal_in, dir);
	dot_out = vec_dot(normal_out, dir);
	if (dot_in < dot_out)
		return (normal_out);
	return (normal_in);
}

static double	distance_center_to_point(t_hit_point hit, t_object *cap)
{
	t_vec3	center_to_point;
	double	distance_center_to_point;

	center_to_point = vec_substract(hit.point, cap->center);
	distance_center_to_point = sqrt(vec_dot(center_to_point, center_to_point));
	return (distance_center_to_point);
}

void	hit_cap(t_ray *ray, t_object *cap, double shadow, t_hit_point *hit)
{
	t_vec3		normal;
	t_vec3		distance_from_origin;
	double		denom;

	(void)shadow;
	hit->status = 0;
	distance_from_origin = vec_substract(cap->center, ray->origin);
	normal = get_normal(cap, ray->dir);
	denom = vec_dot(normal, ray->dir);
	if (denom > __DBL_EPSILON__)
	{
		hit->root = vec_dot(distance_from_origin, normal) / denom;
		if (hit->root >= __DBL_EPSILON__)
		{
			hit->point = vec_add(ray->origin, vec_scalar(ray->dir, hit->root));
			if (distance_center_to_point(*hit, cap) < cap->radius)
			{
				hit->status = 1;
			}
		}
	}
}
