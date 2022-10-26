/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:25:59 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/26 16:52:12 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static double	get_root(int shadow, double discr, t_hit_point hit)
{
	double		t1;
	double		t2;
	double		root;

	t1 = (-hit.b - sqrt(discr)) / (2.0 * hit.a);
	t2 = (-hit.b + sqrt(discr)) / (2.0 * hit.a);
	if (!shadow)
	{
		if (t1 < t2 && t1 > __DBL_EPSILON__)
			root = t1;
		else
			root = t2;
	}
	else
	{
		if (t1 < t2)
			root = t1;
		else
			root = t2;
	}
	return (root);
}

t_hit_point	hit_cy(t_ray *ray, t_object *cy, double shadow)
{
	t_hit_point	hit;
	double		discr;
	double		tmp;
	double		hit_disk;

	hit.oc = vec_substract(ray->origin, cy->center);
	hit.a = vec_dot(ray->dir, ray->dir);
	tmp = vec_dot(ray->dir, cy->dir);
	hit.a = hit.a - (tmp * tmp);
	hit.b = 2.0 * (vec_dot(ray->dir, hit.oc) - tmp * vec_dot(hit.oc, cy->dir));
	hit.c = vec_dot(hit.oc, hit.oc) - cy->radius * cy->radius;
	hit.c -= (vec_dot(hit.oc, cy->dir) * vec_dot(hit.oc, cy->dir));
	discr = hit.b * hit.b - 4.0 * hit.a * hit.c;
	if (discr < __DBL_EPSILON__)
	{
		hit.status = 0;
		return (hit);
	}
	hit.status = 1;
	hit.root = get_root(shadow, discr, hit);
	hit.point = vec_add(ray->origin, vec_scalar(ray->dir, hit.root));
	hit_disk = vec_dot(vec_substract(hit.point, cy->center), cy->dir);
	if (hit_disk < __DBL_EPSILON__ || hit_disk > cy->height)
		hit.status = 0;
	return (hit);
}
