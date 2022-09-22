/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:48:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/21 15:22:44 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static float    get_discr(t_ray *ray, t_world *world, t_object *sp)
{
    t_vec3  oc;
    float   a;
    float   b;
    float   c;
    
    oc = vec_substract(ray->origin, sp->center);
    a = vec_dot(ray->direction, ray->direction);
    b = 2.0 * vec_dot(oc, ray->direction);
    c = vec_dot(oc, oc) - sp->radius * sp->radius;
    discr = b * b - 4 * a * c;
    return (discr);
}

t_vec3    *hit_sp(t_ray *ray, t_world *world, t_object *sp)
{
    float   res;
    float   discr;
    t_vec3  hit_point;

    discr = get_discr(ray, world, sp);
    if (discr < 0)
        return (NULL);
    else
    {
       res = (-b - sqrt(discr)) / (2.0 * a);
       hit_point.x = ray->origin.x + res * ray->direction.x;
       hit_point.y = ray->origin.y + res * ray->direction.y;
       hit_point.z = ray->origin.z + res * ray->direction.z;
    }
    return (hit_point);    
    
}