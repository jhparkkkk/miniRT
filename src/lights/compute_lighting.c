/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:39:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/26 17:08:55 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
/*
// static void	specular_lighting(t_hit_point *hit, t_ray *ray)
// {
// 	hit->reflect = vec_scalar(hit->normal, 2.0);
// 	hit->reflect = vec_scalar(hit->reflect, vec_dot(hit->normal, vec_scalar(hit->vec_light, 1.0)));
// 	hit->reflect = vec_substract(hit->reflect, hit->vec_light);
// 	hit->view = vec_scalar(ray->dir, -1.0);
// 	hit->rdotv = sqrt(vec_dot(hit->reflect, hit->view));
// }
*/

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
double	compute_lighting(t_ray *ray, t_object *obj, t_world *world)
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
	hit.vec_light = vec_substract(hit.point, world->light.position);
	hit.ndotl = sqrt(vec_dot(hit.normal, hit.vec_light));
	if (hit.ndotl > __DBL_EPSILON__ && shadow(hit.point, hit.vec_light, world))
	{
		intens += (hit.ndotl / (vec_len(hit.normal) * vec_len(hit.vec_light)));
		intens *= world->light.intens;
		/* SPEC LIGHTNING */
		// if (obj->specular_exponent != -1.0)
		// {
		// 	specular_lighting(&hit, ray);
		// 	if (hit.rdotv > __DBL_EPSILON__) // si M_E bug et il faut remettre 0.0 puis M_E
		// 	{	
		// 		intens += world->light.intens * (obj->k_spec * pow(hit.rdotv / (vec_len(hit.reflect) * vec_len(hit.view)), obj->specular_exponent * 500000.0));
		// 	}
		// 		// obj->specular_exponent = world->light.intens * pow(hit.rdotv, obj->specular_exponent);
		// }
	}
	return (intens);
}
