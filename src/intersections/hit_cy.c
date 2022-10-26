/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:25:59 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/23 18:05:56 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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
	//Check if point in cylinder => check the caps
	hit.point = vec_add(ray->origin, vec_scalar(ray->direction, hit.root));
	// if (sqrt(vec_dot(vec_substract(hit.point, cy->center), vec_substract(hit.point, cy->center)) > cy->height))
	double hit_disk = vec_dot(vec_substract(hit.point, cy->center), cy->direction);
	if (hit_disk < __DBL_EPSILON__ || hit_disk > cy->height)
		hit.status = 0;
	return (hit);
}