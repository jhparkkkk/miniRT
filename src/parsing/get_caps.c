/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_caps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:23:51 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/23 15:03:47 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_object	*get_btm_cap(t_object *cy, t_object *cap)
{
	cap->type = CIRC_PLANE;
	cap->center = cy->center;
	cap->direction = vec_scalar(cy->direction, 1.0);
	cap->direction = vec_normalize(cap->direction);
	cap->color = vec_init(255.0,0.0,0.0);
	// cap->color = cy->color;
	cap->surface = cy->surface;
	cap->radius = cy->radius;
	cap->intersect = hit_cap;
	cap->print_object = &print_cap;
	return (cap);
}

static t_object	*get_top_cap(t_object *cy, t_object *cap)
{
	cap->type = CIRC_PLANE;
	cap->direction = vec_scalar(cy->direction, -1.0);
	cap->direction = vec_normalize(cap->direction);
	cap->center = vec_add(cy->center, vec_scalar(cy->direction, cy->height));
	cap->color = vec_init(0.0,0.0,255.0);
	// cap->color = cy->color;
	cap->surface = cy->surface;
	cap->radius = cy->radius;
	cap->intersect = hit_cap;
	cap->print_object = &print_cap;
	return (cap);
}

void	get_caps(t_object **objects, t_object *cy, int *idx)
{
	t_object *top_cap;
	t_object *btm_cap;
	
	btm_cap = ft_memory(sizeof(t_object), 1);
	top_cap = ft_memory(sizeof(t_object), 1);
	objects[(*idx)++] = get_btm_cap(cy, btm_cap);
	objects[(*idx)++] = get_top_cap(cy, top_cap);
}