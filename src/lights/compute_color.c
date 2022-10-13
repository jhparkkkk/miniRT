/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:48:38 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/29 14:24:45 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_vec3 global_light(double intensity, t_light light,
	t_ambient_light ambient_light)
{
	t_vec3	light_1;
	t_vec3	light_2;
	
	light_1 = vec_scalar(light.color, intensity * K_DIFFUSE);
	light_2 = vec_scalar(ambient_light.color, ambient_light.intensity * K_AMBIENT);
	return (vec_add(light_1, light_2));
}

static	t_vec3 get_object_shade(t_vec3 color, double light_intensity, double ambient_intensity)
{
	t_vec3	ambient_to_obj;
	t_vec3	light_to_obj;
	
	ambient_to_obj = vec_scalar(color, ambient_intensity * K_AMBIENT);
	light_to_obj = vec_scalar(color, light_intensity * K_DIFFUSE);
	return (vec_add(ambient_to_obj, light_to_obj));
}

/*Returns the pixel color regarding the lights and ambient light in *world at
*the impact of the *ray and the *object */
int	compute_color(t_ray *ray, t_object *object, t_world *world)
{
	double	intensity;
	t_vec3	color;
	t_vec3	light_global;
	t_vec3	object_shade;
	
	intensity = compute_lighting(ray, object, world);
	light_global = global_light(intensity, world->light, world->ambient_light);
	object_shade = get_object_shade(object->color, intensity, world->ambient_light.intensity);
	color = vec_add(object_shade, light_global);
	return get_hex_color(color);
}