/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:16:25 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/26 13:26:04 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#define BIAS 1e-50

// #define BIAS 1e-80

static void	set_ray_from_light(t_ray *ray, t_vec3 point, t_vec3 light)
{
	ray->origin = point;
	// ray->origin = vec_scalar(point, __DBL_EPSILON__);
	ray->dir = vec_scalar(light, -1.0);
	ray->dir = vec_normalize(ray->dir);
	ray->hit.root = 0.0;
	ray->hit.a = 0.0;
	ray->hit.b = 0.0;
	ray->hit.c = 0.0;
	ray->hit.ndotl = 0.0;
	ray->hit.rdotv = 0.0;
}

/*If the ray sent from the point to the light touches an object, returns 0. Else
return 1.*/
int	shadow(t_vec3 point, t_vec3 vec_light, t_world *world)
{
	t_ray	ray;
	t_vec3	light_hit;
	double	len_light;
	double	len_light_to_hit;

	set_ray_from_light(&ray, point, vec_light);
	len_light = sqrt(vec_dot(vec_light, vec_light));
	if (hit_obj(&ray, world, 1) > -1)
	{
		light_hit = vec_scalar(ray.dir, ray.hit.root);
		light_hit = vec_add(ray.origin, light_hit);
		light_hit = vec_substract(light_hit, world->light.position);
		len_light_to_hit = sqrt(vec_dot(light_hit, light_hit));
		if (len_light_to_hit < len_light && vec_dot(light_hit, vec_light) > __DBL_EPSILON__)
			return (0);
	}
	return (1);
}
