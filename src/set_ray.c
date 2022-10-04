/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/04 15:00:08 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_ray	set_ray(t_cam cam, int x, int y, t_viewport viewport)
{
	t_ray	ray;
	
	ray.origin = cam.position;
	// ray.direction.x = x - SIZEX / 2;
	// ray.direction.y = -y + SIZEY / 2;
	// ray.direction.x *= cam.hfov;
	// ray.direction.y *= cam.vfov;
	// ray.direction.z = 0;
	ray.direction = vec_add(viewport.lower_left_corner, vec_scalar(viewport.horizontal, x));
	ray.direction = vec_add(ray.direction, vec_scalar(viewport.vertical, y));
	ray.direction = vec_substract(ray.direction, ray.origin);
	
	// ray.direction = vec_add(ray.direction, cam.direction);
	
	ray.direction = vec_normalize(ray.direction);
	
	// ray.direction = vec_add(ray.direction, vec_scalar(cam.direction, vec_len(ray.direction)));
	// ray.direction = vec_normalize(ray.direction);
	return (ray);
}