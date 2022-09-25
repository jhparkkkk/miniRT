/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 11:10:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/25 14:29:31 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	hit_obj(t_ray *ray, t_world *world)
{
	int			i;
	int			idx;
	int			touch;
	float		root_min;
	t_hit_point	hit;

	i = 0;
	touch = 0;
	root_min = INFINITY;
	while (world->objects[i])
	{
		hit = world->objects[i]->intersect(ray, world->objects[i]);
		if (hit.status)
		{
			if (hit.root < root_min)
			{
				root_min = hit.root;
				idx = i;
			}
			touch = 1;
		}
		i++;
	}
	printf("8");
	if (!touch)
		return (-1);
	return (idx); 
}