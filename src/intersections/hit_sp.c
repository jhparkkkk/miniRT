/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:48:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/26 14:59:33 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_hit_point hit_sp(t_ray *ray, t_object *sp, double shadow)
{
    double   	discr;
	double		t1;
	double		t2;
	t_hit_point hit;
    
	hit.status = 0;
	hit.root = 0.0;
    hit.oc = vec_substract(ray->origin, sp->center);
    hit.a = vec_dot(ray->direction, ray->direction);
    hit.b = 2.0 * vec_dot(hit.oc, ray->direction);
    hit.c = vec_dot(hit.oc, hit.oc) - sp->radius * sp->radius;
    discr = hit.b * hit.b - 4.0 * hit.a * hit.c;
    if (discr < __DBL_EPSILON__)
	{
		hit.status = 0;
        return (hit);
	}
	hit.status = 1;
	t1 = (- hit.b - sqrt(discr)) / (2.0 * hit.a);
	t2 = (- hit.b + sqrt(discr)) / (2.0 * hit.a);
	// if (t1 < t2 || t1 >= __DBL_EPSILON__)
	// 	hit.root = t1;
	// else
	// 	hit.root = t2;
	if (!shadow)
	{
		if (t1 < t2 && t1 > __DBL_EPSILON__)
			hit.root = t1;
		else
			hit.root = t2;
	}
	else
	{
		if (t1 < t2)
			hit.root = t1;
		else
			hit.root = t2;
	}

    return (hit);     
}