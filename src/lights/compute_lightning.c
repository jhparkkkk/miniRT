/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lightning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:39:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/25 17:09:45 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	compute_lightning(t_world world, t_object obj, t_ray *ray)
{
	double	i;
	t_vec3	vec_light;
	t_vec3	point;
	t_vec3	normal;

	point = vec_add(ray->origin, vec_scalar(ray->direction, ray->hit_point.root))
	normal = vec_substract(point, obj.center);
	normal = vec_scalar(normal, 1 / vec_len(normal));
	i = world.ambient_light.intensity;
	vec_light = vec_substract(world.light.position, point);
	
}
