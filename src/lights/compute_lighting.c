/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:39:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/28 16:51:07 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_vec3	get_cy_normal(t_vec3 point, t_object *obj)
{
	t_vec3	to_point;
	t_vec3	new_center;
	t_vec3	normal;

	to_point = vec_substract(point, obj->center);
	new_center = vec_scalar(obj->dir, vec_dot(to_point, obj->dir));
	normal = vec_scalar(vec_substract(to_point, new_center), -1.0);
	return (normal);
}

/* Calculates the intens of light at the impact of *ray on the *sphere.
Returns the intens. */
double	compute_lighting(t_ray *ray, t_object *obj, t_world *world,
	t_light light)
{
	t_hit_point	hit;
	double		intens;

	intens = 0.0;
	hit.point = vec_add(ray->origin, vec_scalar(ray->dir, ray->hit.root));
	if (obj->type == PLANE || obj->type == CIRC_PLANE)
		hit.normal = vec_scalar(obj->dir, 1.0);
	else if (obj->type == SPHERE)
		hit.normal = vec_substract(obj->center, hit.point);
	else if (obj->type == CYLINDER)
		hit.normal = get_cy_normal(hit.point, obj);
	hit.vec_light = vec_substract(hit.point, light.position);
	hit.ndotl = sqrt(vec_dot(hit.normal, hit.vec_light));
	if (hit.ndotl > __DBL_EPSILON__
		&& shadow(hit.point, hit.vec_light, world, light))
	{
		intens += (hit.ndotl / (vec_len(hit.normal) * vec_len(hit.vec_light)));
		intens *= light.intens;
	}
	return (intens);
}
