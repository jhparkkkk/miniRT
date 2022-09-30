/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:48:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/30 16:08:40 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_hit_point hit_sp(t_ray *ray, t_object *sp)
{
    double   	discr;
	double		t1;
	double		t2;
	t_hit_point hit;
    
	hit.status = 0;
	hit.root = 0;
    hit.oc = vec_substract(sp->center, ray->origin);
    hit.a = vec_dot(ray->direction, ray->direction);
    hit.b = 2.0 * vec_dot(hit.oc, ray->direction);
    hit.c = vec_dot(hit.oc, hit.oc) - sp->radius * sp->radius;
    discr = hit.b * hit.b - 4.0 * hit.a * hit.c;
    if (discr < 0.0)
	{
		hit.status = 0;
        return (hit);
	}
	hit.status = 1;
	t1 = (- hit.b - sqrtf(discr)) / (2.0 * hit.a);
	t2 = (- hit.b + sqrtf(discr)) / (2.0 * hit.a);
	if (t1 < t2)
		hit.root = t1;
	else
		hit.root = t2;
    // else
    // {
    //    hit.x = ray->origin.x + res * ray->direction.x;
    //    hit.y = ray->origin.y + res * ray->direction.y;
    //    hit.z = ray->origin.z + res * ray->direction.z;
    // }
    return (hit);     
}