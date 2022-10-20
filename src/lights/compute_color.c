/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:48:38 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/19 18:33:41 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_vec3 global_light(double intensity, t_light light,
	t_ambient_light ambient_light, t_object *object)
{
	t_vec3	diffuse;
	t_vec3	ambient;
	t_vec3	specular;
	
	diffuse = vec_scalar(light.color, intensity * K_DIFFUSE);
	ambient = vec_scalar(ambient_light.color, ambient_light.intensity * K_AMBIENT);
	specular = vec_scalar(light.color, intensity * (object->k_spec / 100)); //A check
	return (vec_add(specular, vec_add(diffuse, ambient)));
	// }
	// return (vec_add(diffuse, ambient));
}

static	t_vec3 get_object_shade(t_vec3 color, double light_intensity,
	double ambient_intensity, t_object *object)
{
	t_vec3	ambient_to_obj;
	t_vec3	light_to_obj;
	
	ambient_to_obj = vec_scalar(color, ambient_intensity * K_AMBIENT);
	light_to_obj = vec_scalar(color, light_intensity * K_DIFFUSE + light_intensity * (object->k_spec / 50));
	// light_to_obj = vec_add(light_to_obj, vec_scalar(color, object->specular_exponent * K_SPEC));
	return (vec_add(ambient_to_obj, light_to_obj));
}

// static t_vec3 get_amb(t_ambient_light ambient_light)
// {
// 	return(vec_scalar(ambient_light.color, K_AMBIENT * ambient_light.intensity));
// }

// static t_vec3 get_l(t_light light, double intensity)
// {
// 	return (vec_scalar(light.color, K_DIFFUSE * intensity));
// }

/*Returns the pixel color regarding the lights and ambient light in *world at
*the impact of the *ray and the *object */
int	compute_color(t_ray *ray, t_object *object, t_world *world, t_hit_point hit)
{
	double	intensity;
	t_vec3	color;
	t_vec3	light_global;
	t_vec3	object_shade;
	
	intensity = compute_lighting(ray, object, world, hit);
	light_global = global_light(intensity, world->light, world->ambient_light, object);
	object_shade = get_object_shade(object->color, intensity, world->ambient_light.intensity, object);
	color = vec_add(object_shade, light_global);
	
	return get_hex_color(color);

/*Ca fait la meme chose*/
	// t_vec3	light_color;
	// t_vec3	object_color;
	// double	intensity;

	// (void)ray;
	// (void)object;
	// intensity = compute_lighting(ray, object, world);
	
	// light_color = vec_add(get_amb(world->ambient_light), get_l(world->light, intensity));
	
	// object_color = vec_scalar(object->color, world->ambient_light.intensity * K_AMBIENT
	// 											+ intensity * K_DIFFUSE);
	// return get_hex_color(vec_add(light_color, object_color));
	
}