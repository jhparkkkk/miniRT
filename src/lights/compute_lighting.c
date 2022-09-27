/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:39:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/27 15:50:38 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	compute_lighting(t_ray *ray, t_object *sp, t_world *world)
{
	t_vec3 point;
	t_vec3 normal;
	t_vec3 vec_light;
	double intensity;
	double n_dot_l;

	
	intensity = 0.0;
	// intensity += world->ambient_light.intensity;
	point = vec_add(ray->origin, vec_scalar(ray->direction, ray->root));
	normal = vec_substract(sp->center, point);
	normal = vec_divide(normal, vec_len(normal)); // normaliser la normale
	vec_light = vec_substract(world->light.position, point);
	n_dot_l = vec_dot(normal, vec_light);
	if (n_dot_l > 0.0)
		intensity += world->light.intensity * n_dot_l / (vec_len(normal) * vec_len(vec_light));
	
	// /* COLOR LIGHTING */
	// world->light.intensity_r = vec_dot(normal, vec_light) * world->ambient_light.intensity * 0.5 * 0 + intensity * 0.5 * 0;
	// world->light.intensity_g = world->ambient_light.intensity * 0.5 * 0 + intensity * 0.5 * 0;
	// world->light.intensity_b = world->ambient_light.intensity * 0.5 * 255.0 + intensity * 0.5 * 255.0;

	// vec3 ala
	
	
	
	/* SPEC LIGHTNING */
	t_vec3	reflect;
	t_vec3	view;
	double r_dot_v;
	if (sp->specular_exponent != -1.0)
	{
		reflect = vec_scalar(normal, 2.0);
		reflect = vec_scalar(reflect, vec_dot(normal, vec_light));
		reflect = vec_substract(reflect, vec_light);
		view = vec_scalar(ray->direction, -1.0);
		r_dot_v = vec_dot(reflect, view);
		if (r_dot_v > 0.0)
			// intensity += (world->light.intensity * r_dot_v * sp->specular_exponent) / (vec_len(reflect) * vec_len(view));
			intensity += world->light.intensity * pow(r_dot_v / (vec_len(reflect) * vec_len(view)), sp->specular_exponent);
	}
	return (intensity);
}