/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:39:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/26 11:54:20 by jeepark          ###   ########.fr       */
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
	intensity += world->ambient_light.intensity;
	point = vec_add(ray->origin, vec_scalar(ray->direction, ray->root));
	normal = vec_substract(sp->center, point);
	normal = vec_divide(normal, vec_len(normal));
	vec_light = vec_substract(world->light.position, point);
	n_dot_l = vec_dot(normal, vec_light);
	if (n_dot_l > 0.0)
		intensity += world->light.intensity * n_dot_l / (vec_len(normal) * vec_len(vec_light)); 
	return (intensity);
}