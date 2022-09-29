/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:39:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/29 10:52:46 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/* n dot l tells how the point and the light are aoriented one vs the other */

double	compute_lighting(t_ray *ray, t_object *sp, t_world *world)
{
	t_vec3 point;
	t_vec3 normal;
	t_vec3 vec_light;
	double intensity;
	double n_dot_l;

	
	intensity = 0.0;
	point = vec_add(ray->origin, vec_scalar(ray->direction, ray->root));
	normal = vec_substract(sp->center, point);
	normal = vec_divide(normal, vec_len(normal)); // normaliser la normale
	vec_light = vec_substract(world->light.position, point);
	n_dot_l = vec_dot(normal, vec_light);
	if (n_dot_l > 0.0)
		intensity += world->light.intensity * (n_dot_l / (vec_len(normal) * vec_len(vec_light)));
	
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
			intensity += world->light.intensity * pow(r_dot_v / vec_len(reflect) * vec_len(view), sp->specular_exponent);
	}
	return (intensity);
}