/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:10:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/18 18:53:32 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/*Returns -1 if the ray didn't intersect any object. Returns -2 if the ray
intersected an object and there was a shadow. Else returns the idx of the
intersected object.*/
int	hit_obj(t_ray *ray, t_world *world, double min, double max, int	shadow)
{
	// int			i;
	// int			idx;
	// int			touch;
	// double		root_min;
	// t_hit_point	hit;

	// (void)shadow;
	// i = 0;
	// touch = 0;
	// root_min = INFINITY;
	// while (world->objects[i])
	// {
	// 	hit = world->objects[i]->intersect(ray, world->objects[i]);
	// 	if (hit.status && hit.root > min && hit.root < max)
	// 	{
	// 		touch = 1;
	// 		if (hit.root < root_min)
	// 		{
	// 			root_min = hit.root;
	// 			idx = i;
	// 		}
	// 	}
	// 	i++;
	// }
	// if (!touch)
	// 	return (-1);
	// ray->root = root_min;
	// return (idx); 
	int			i;
	int			idx;
	int			touch;
	double		root_min;

	(void)min;
	i = 0;
	touch = 0;
	root_min = INFINITY;
	while (world->objects[i])
	{
		ray->hit = world->objects[i]->intersect(ray, world->objects[i], shadow);
		if (ray->hit.status && ray->hit.root > __DBL_EPSILON__ && ray->hit.root < max)
		{
			touch = 1;
			if (ray->hit.root < root_min)
			{
				root_min = ray->hit.root;
				idx = i;
			}
		}
		i++;
	}
	if (!touch)
		return (-1);
	ray->hit.root = root_min;
	return (idx); 
}