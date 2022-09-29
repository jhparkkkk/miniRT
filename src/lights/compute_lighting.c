/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:39:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/29 13:44:22 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static double	specular_lighting(t_hit_point *hit, t_ray *ray)
{
	hit->reflect = vec_scalar(hit->normal, 2.0);
	hit->reflect = vec_scalar(hit->reflect, vec_dot(hit->normal, hit->vec_light));
	hit->reflect = vec_substract(hit->reflect, hit->vec_light);
	hit->view = vec_scalar(ray->direction, -1.0);
	hit->r_dot_v = vec_dot(hit->reflect, hit->view);
	return (hit->r_dot_v);
}

/* Calculates the intensity of light at the impact of *ray on the *sphere.
Returns the intensity. */
double	compute_lighting(t_ray *ray, t_object *sp, t_world *world)
{
	t_hit_point	hit;
	double intensity;
	
	intensity = 0.0;
	hit.point = vec_add(ray->origin, vec_scalar(ray->direction, ray->root));
	hit.normal = vec_substract(sp->center, hit.point);
	hit.normal = vec_divide(hit.normal, vec_len(hit.normal));
	hit.vec_light = vec_substract(world->light.position, hit.point);
	hit.n_dot_l = vec_dot(hit.normal, hit.vec_light);
	if (hit.n_dot_l > 0.0)
		intensity += world->light.intensity * (hit.n_dot_l / (vec_len(hit.normal) * vec_len(hit.vec_light)));
	
	/* SPEC LIGHTNING */
	if (sp->specular_exponent != -1.0)
	{
		if (specular_lighting(&hit, ray) > 0.0)
			intensity += (world->light.intensity * (hit.r_dot_v / (vec_len(hit.reflect) * vec_len(hit.view)))* sp->specular_exponent) ;
			// intensity += world->light.intensity * pow(hit.r_dot_v / (vec_len(hit.reflect) * vec_len(hit.view)), 1 / sp->specular_exponent);
	}
	return (intensity);
}