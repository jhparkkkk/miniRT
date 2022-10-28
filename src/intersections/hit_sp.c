/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:48:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/28 14:28:13 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static double	get_root(int shadow, double discr, t_hit_point *hit)
{
	double		t1;
	double		t2;
	double		root;

	t1 = (-hit->b - sqrt(discr)) / (2.0 * hit->a);
	t2 = (-hit->b + sqrt(discr)) / (2.0 * hit->a);
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

void	hit_sp(t_ray *ray, t_object *sp, double shadow, t_hit_point *hit)
{
	double		discr;

	hit->status = 0;
	hit->root = 0.0;
	hit->oc = vec_substract(ray->origin, sp->center);
	hit->a = vec_dot(ray->dir, ray->dir);
	hit->b = 2.0 * vec_dot(hit->oc, ray->dir);
	hit->c = vec_dot(hit->oc, hit->oc) - sp->radius * sp->radius;
	discr = hit->b * hit->b - 4.0 * hit->a * hit->c;
	if (discr < __DBL_EPSILON__)
	{
		hit->status = 0;
	}
	else
	{
		hit->status = 1;
		hit->root = get_root(shadow, discr, hit);
	}
}
