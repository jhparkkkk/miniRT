/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:48:38 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/27 15:20:31 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_vec3	g_light(t_hit_point hit, t_light light,
	t_amb_light amb_light, t_object *object)
{
	t_vec3	diffuse;
	t_vec3	ambient;
	t_vec3	specular;

	(void)object;
	diffuse = vec_scalar(light.color, hit.intens * K_DIFFUSE);
	specular = vec_scalar(light.color, hit.spec * 2e-20);
	ambient = vec_scalar(amb_light.color, amb_light.intens * K_AMBIENT);
	// return (vec_add(diffuse, ambient));
	return (vec_add(specular, vec_add(diffuse, ambient)));
}

static t_vec3	get_shade(t_vec3 color, t_hit_point hit,
	double ambient_intens, t_object *object)
{
	t_vec3	ambient_to_obj;
	t_vec3	light_to_obj;
	// t_vec3	specular_to_obj;

	(void)object;
	ambient_to_obj = vec_scalar(color, ambient_intens * K_AMBIENT);
	light_to_obj = vec_scalar(color, hit.intens * K_DIFFUSE);
	// specular_to_obj = vec_scalar(color, hit.spec * 100.0);
	return (vec_add(ambient_to_obj, light_to_obj));
	// return (vec_add(vec_add(ambient_to_obj, light_to_obj), specular_to_obj));
}

t_vec3	vec_multiply(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = (v1.x * v2.x) / 255;
	res.y = (v1.y * v2.y) / 255;
	res.z = (v1.z * v2.z) / 255;
	return (res);
}

/*Returns the pixel color regarding the lights and ambient light in *world at
*the impact of the *ray and the *object */
int	compute_color(t_ray *ray, t_object *obj, t_world *world)
{
	t_hit_point	hit;
	t_vec3		color;
	t_vec3		global;
	t_vec3		ob_shade;
	int			i;

	// intens = 0.0;
	i = 0;
	color = vec_init(0, 0, 0);
	while (i < world->nb_light)
	{
		hit = compute_lighting(ray, obj, world, *(world)->lights[i]);
		global = g_light(hit, *(world)->lights[i], world->amb_light, obj);
		ob_shade = get_shade(obj->color, hit, world->amb_light.intens, obj);
		color = vec_add(color, vec_multiply(ob_shade, global));
		i++;
	}
	return (get_hex_color(color));
}
