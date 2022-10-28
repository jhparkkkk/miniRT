/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:10:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/28 14:34:29 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	refresh_hit_obj(int i, double *root_min, int *idx, t_ray *ray)
{
	if (ray->hit.root < (*root_min))
	{
		(*root_min) = ray->hit.root;
		(*idx) = i;
	}
}

/*Returns -1 if the ray didn't intersect any object. Returns -2 if the ray
intersected an object and there was a shadow. Else returns the idx of the
intersected object.*/
int	hit_obj(t_ray *ray, t_world *world, int shadow)
{
	int			i;
	int			idx;
	int			touch;
	double		root_min;

	i = 0;
	touch = 0;
	root_min = INFINITY;
	while (world->objects[i])
	{
		world->objects[i]->intersect(ray, world->objects[i],
			shadow, &ray->hit);
		if (ray->hit.status && ((shadow && ray->hit.root > 1.0e-12)
				|| (!shadow && ray->hit.root > __DBL_EPSILON__))
			&& ray->hit.root < INFINITY)
		{
			refresh_hit_obj(i, &root_min, &idx, ray);
			touch = 1;
		}
		i++;
	}
	if (!touch)
		return (-1);
	ray->hit.root = root_min;
	return (idx);
}
