/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_pl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:35:18 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/18 15:02:52 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_hit_point	hit_pl(t_ray *ray, t_object *pl)
{
	t_vec3		normal; //orientation
	t_vec3		distance_from_origin; //position
	double		denom;
	t_hit_point hit;

	normal = pl->direction; // pl direction est normalisé dans le create pl
	distance_from_origin = vec_substract(pl->center, ray->origin);
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
	hit.status = 0;
	return (hit);
}