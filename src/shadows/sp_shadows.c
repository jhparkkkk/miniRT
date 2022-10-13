/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_shadows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:16:25 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/12 16:34:15 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	set_ray_to_light(t_ray *ray, t_vec3 point, t_vec3 light)
{
	ray->origin = point;
	ray->direction = vec_scalar(light, -1.0);
	ray->direction = vec_normalize(ray->direction);
}

/*If the ray sent from the point to the light touches an object, returns 0. Else
return 1.*/
int	sp_shadows(t_vec3 point, t_vec3 light, t_world *world)
{
	t_ray ray;

	set_ray_to_light(&ray, point, light);
	if (hit_obj(&ray, world, __DBL_EPSILON__, 1.0, 1) == -2)
	{
		return (0);
	}
	return (1);
	
}