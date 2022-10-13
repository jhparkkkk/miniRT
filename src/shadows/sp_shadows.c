/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:16:25 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/13 15:40:06 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	set_ray_from_light(t_ray *ray, t_vec3 point, t_vec3 light, t_world *world)
{
	(void)point;
	ray->origin = world->light.position;
	ray->direction = vec_scalar(light, -1.0);
	ray->direction = vec_normalize(ray->direction);
}

/*If the ray sent from the point to the light touches an object, returns 0. Else
return 1.*/
int	sp_shadows(t_vec3 point, t_vec3 vec_light, t_world *world)
{
	t_ray ray;
	// t_vec3 new_point;
	double	distance;
	
	set_ray_from_light(&ray, point, vec_light, world);
	distance = vec_len(vec_light);
	if (hit_obj(&ray, world, __DBL_EPSILON__, distance, 1) > -1)
	{
		// new_point = vec_add(ray.origin, vec_scalar(ray.direction, ray.root));
		// if (vec_compare(new_point, point))
			return (0);
	}
	return (1);
	
}