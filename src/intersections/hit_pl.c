/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_pl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:35:18 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/26 16:36:05 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_vec3	get_normal(t_object *pl, t_vec3 dir)
{
	double		dot_in;
	double		dot_out;
	t_vec3		normal_in;
	t_vec3		normal_out;

	normal_in = pl->dir;
	normal_out = vec_scalar(pl->dir, -1.0);
	dot_in = vec_dot(normal_in, dir);
	dot_out = vec_dot(normal_out, dir);
	if (dot_in < dot_out)
		return (normal_out);
	return (normal_in);
}

t_hit_point	hit_pl(t_ray *ray, t_object *pl, double shadow)
{
	t_vec3		normal;
	t_vec3		distance_from_origin;
	double		denom;
	t_hit_point	hit;

	(void)shadow;
	hit.status = 0;
	distance_from_origin = vec_substract(pl->center, ray->origin);
	normal = get_normal(pl, ray->dir);
	denom = vec_dot(normal, ray->dir);
	if (denom > __DBL_EPSILON__)
	{
		hit.root = vec_dot(distance_from_origin, normal) / denom;
		if (hit.root >= __DBL_EPSILON__)
		{
			hit.status = 1;
			return (hit);
		}
	}
	return (hit);
}
