/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/05 16:39:11 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vec3	mat_multiply_vec(double **mat, t_vec3 vec)
{
	t_vec3 res;

	res.x = mat[0][0] * vec.x + mat[0][1] * vec.y + mat[0][2] * vec.z + mat[0][3];
	res.y = mat[1][0] * vec.x + mat[1][1] * vec.y + mat[1][2] * vec.z + mat[1][3];
	res.z = mat[2][0] * vec.x + mat[2][1] * vec.y + mat[2][2] * vec.z + mat[2][3];

	return (res);
}

t_ray	set_ray(t_cam cam, int x, int y)
{
	t_ray	ray;
	
	double	scale = tan(degrees_to_radians(cam.vfov * 0.5));
	double	imageAspectRatio = (double)SIZEX / (double)SIZEY;
    // double	Px = (2.0 * (x + 0.5) / (double)SIZEX - 1.0) * imageAspectRatio * scale; 
    // double	Py = (1.0 - 2.0 * (y + 0.5) / (double)SIZEY) * scale;
	
	double px = (2 * (x + 0.5) / (double)SIZEX - 1) * imageAspectRatio * scale; 
    double py = (1 - 2 * (y + 0.5) / (double)SIZEY) * scale; 

	ray.origin = cam.position;
	// ray.origin = mat_multiply_vec(cam.lookat, ray.origin);
	// ray.origin = vec_normalize(ray.origin);

	ray.direction = mat_multiply_vec(cam.lookat, vec_init(px, py, -1));
	ray.direction = vec_normalize(ray.direction);
	
	return (ray);
}