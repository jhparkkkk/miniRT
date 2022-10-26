/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_pl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:35:18 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/26 11:35:23 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_vec3 get_normal(t_object *pl, t_vec3 dir)
{
	double dot_in;
	double dot_out;
	t_vec3		normal_in; //orientation
	t_vec3		normal_out; //orientation

	normal_in = pl->direction;
	normal_out = vec_scalar(pl->direction, -1.0);
	dot_in = vec_dot(normal_in, dir);
	dot_out = vec_dot(normal_out, dir);
	if (dot_in < dot_out)
		return (normal_out);
	return (normal_in);
}

t_hit_point	hit_pl(t_ray *ray, t_object *pl, double shadow)
{
	t_vec3		normal; //orientation
	t_vec3		distance_from_origin; //position
	double		denom;
	t_hit_point hit;
	(void)shadow;

	// if (!shadow)
	// 	normal = get_normal(pl, ray->direction);
	// else
	// 	normal = pl->direction;
	hit.status = 0;
	distance_from_origin = vec_substract(pl->center, ray->origin);
	normal = get_normal(pl, ray->direction);
	denom = vec_dot(normal, ray->direction);
	if (denom > __DBL_EPSILON__) // si proche de 0 c'est parallele
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

// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   hit_pl.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/10/18 13:35:18 by cgosseli          #+#    #+#             */
// /*   Updated: 2022/10/25 17:40:16 by cgosseli         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "mini_rt.h"

// static t_vec3 get_normal(t_object *pl, t_vec3 dir)
// {
// 	double dot_in;
// 	double dot_out;
// 	t_vec3		normal_in; //orientation
// 	t_vec3		normal_out; //orientation

// 	normal_in = pl->direction;
// 	normal_out = vec_scalar(pl->direction, -1.0);
	
// 	dot_in = vec_dot(normal_in, dir);
// 	dot_out = vec_dot(normal_out, dir);
// 	if (dot_in < dot_out)
// 		return (normal_out);
// 	return (normal_in);
// }

// t_hit_point	hit_pl(t_ray *ray, t_object *pl, double shadow)
// {
// 	t_vec3		normal; //orientation
// 	t_vec3		distance_from_origin; //position
// 	double		denom;
// 	t_hit_point hit;

// 	if (shadow)
// 		normal = get_normal(pl, ray->direction);
// 	else
// 		normal = pl->direction;
// 		// normal = get_normal(pl, ray->direction);
// 	distance_from_origin = vec_substract(pl->center, ray->origin);
// 	denom = vec_dot(normal, ray->direction);
// 	if (denom > __DBL_EPSILON__) // si proche de 0 c'est parallele
// 	{
// 		hit.root = vec_dot(distance_from_origin, normal) / denom;
// 		if (hit.root >= __DBL_EPSILON__)
// 		{
// 			hit.status = 1;
// 			return (hit);
// 		}
// 	}
// 	hit.status = 0;
// 	return (hit);
// }