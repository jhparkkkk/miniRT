/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:16:25 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/17 18:23:44 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	set_ray_from_light(t_ray *ray, t_vec3 point, t_vec3 light)
{
	ray->origin = point;
	ray->direction = vec_scalar(light, -1.0);
	ray->direction = vec_normalize(ray->direction);
}

/*If the ray sent from the point to the light touches an object, returns 0. Else
return 1.*/
int	sp_shadows(t_vec3 point, t_vec3 vec_light, t_world *world)
{
	t_ray	ray;
	t_vec3	light_hit;
	double	len_light;
	double	len_light_to_hit;

	set_ray_from_light(&ray, point, vec_light);
	len_light = sqrt(vec_dot(vec_light, vec_light));
	if (hit_obj(&ray, world, 0.001, INFINITY, 1) > -1)
	{
		light_hit = vec_scalar(ray.direction, ray.hit.root);
		light_hit = vec_add(ray.origin, light_hit);
		light_hit = vec_substract(light_hit, world->light.position);
		len_light_to_hit = sqrt(vec_dot(light_hit, light_hit));
		if (len_light_to_hit < len_light)
			return (0);
	}
	return (1);
}
