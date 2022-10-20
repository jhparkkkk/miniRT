/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:25:59 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/20 15:05:58 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	hit_btm_cap(t_hit_point *hit, t_object *cy, t_ray ray)
{
	t_vec3		normal; //orientation
	t_vec3		point_to_center;
	// t_vec3		distance_from_origin; //position
	double		distance_point_to_center; 
	double		discr;
	
	normal = cy->direction; // pl direction est normalisé dans le create pl
	// distance_from_origin = vec_substract(cy->center, ray.origin);
	discr = vec_dot(normal, ray.direction);
	if (discr > __DBL_EPSILON__) // si proche de 0 c'est parallele
	{
		// hit->root = vec_dot(distance_from_origin, normal) / discr;
		if (hit->root >= __DBL_EPSILON__)
		{
			point_to_center = vec_substract(cy->center, hit->point);
			distance_point_to_center = sqrt(vec_dot(point_to_center, point_to_center));
			if (distance_point_to_center > cy->radius)
			{
				hit->status = 0;
				return (0);
			}
			else
			{
				hit->status = 1;
				return (1);
			}
		}
	}
	return (0);
}

t_hit_point	hit_cy(t_ray *ray, t_object *cy)
{
	t_hit_point hit;
	double   	discr;
	double		t1;
	double		t2;
	
	hit.oc = vec_substract(ray->origin, cy->center);
    hit.a = vec_dot(ray->direction, ray->direction);
	double tmp = vec_dot(ray->direction, cy->direction);
	hit.a = hit.a - (tmp * tmp);
    hit.b = vec_dot(ray->direction, hit.oc);
	hit.b = 2.0 * (hit.b - tmp * vec_dot(hit.oc, cy->direction));
    hit.c = vec_dot(hit.oc, hit.oc) - (vec_dot(hit.oc, cy->direction) * vec_dot(hit.oc, cy->direction)) - cy->radius * cy->radius;
    discr = hit.b * hit.b - 4.0 * hit.a * hit.c;
	 if (discr < __DBL_EPSILON__)
	{
		hit.status = 0;
        return (hit);
	}
	hit.status = 1;
	t1 = (- hit.b - sqrt(discr)) / (2.0 * hit.a);
	t2 = (- hit.b + sqrt(discr)) / (2.0 * hit.a);
	if (t1 < t2 && t1 >= __DBL_EPSILON__)
		hit.root = t1;
	else
		hit.root = t2;
	// Check if point in cylinder => check the caps
	hit.point = vec_add(ray->origin, vec_scalar(ray->direction, hit.root));
	// if (sqrt(vec_dot(vec_substract(hit.point, cy->center), vec_substract(hit.point, cy->center)) > cy->height))
	double hit_disk = vec_dot(vec_substract(hit.point, cy->center), cy->direction);
	if ((hit_disk < __DBL_EPSILON__ || hit_disk > cy->height) && hit_btm_cap(&hit, cy, *ray))
	{
		hit.normal = cy->direction;
	}
	else
	{
		hit.normal = vec_substract(cy->center, hit.point);
	}
	return (hit);
}