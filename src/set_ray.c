/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/04 18:23:48 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_ray	set_ray(t_cam cam, double x, double y, t_viewport viewport)
{
	t_ray	ray;
	
	ray.origin = cam.position;

	// ray.direction = vec_add(viewport.lower_left_corner, vec_scalar(viewport.horizontal, x - SIZEX /2));
	// ray.direction = vec_add(ray.direction, vec_scalar(viewport.vertical,y - SIZEY/2));
	// ray.direction = vec_substract(ray.direction, ray.origin);
	
	// ray.direction = vec_cross(ray.direction, cam.direction);
	
	(void)viewport;
	t_vec3 w_p;
	double imageAspectRatio = (double)SIZEX / (double)SIZEY;
	double Px = (2.0 * ((x + 0.5) / (double)SIZEX) - 1.0) * tan(cam.vfov / 2.0 * M_PI / 180.0) * imageAspectRatio; 
	double Py = (1.0 - 2.0 * ((y + 0.5) / (double)SIZEY) * tan(cam.vfov / 2.0 * M_PI / 180.0)); 
	// ray.direction = vec_substract(vec_init(Px, Py, -1.0), ray.origin);
	// ray.direction = vec_normalize(ray.direction);
	// Vec3f rayDirection = Vec3f(Px, Py, -1) - rayOrigin; 
	return (ray);
}