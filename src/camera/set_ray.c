/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/18 00:05:13 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_ray	set_ray(t_cam cam, int x, int y, double mat[4][4])
{
	t_ray	ray;
	double	aspect_ratio; 
	double	angle;

	/* projection */
	aspect_ratio = (double)SIZEX / (double)SIZEY;
	
	angle = tan(cam.vfov * M_PI / 180.0) ;
	ray.origin = cam.position;
	
	ray.direction.x = (2.0 * (((double)x + 0.5) * (1.0 / (double)SIZEX)) - 1) * angle * aspect_ratio;
	ray.direction.y = (1.0 - 2.0 * (((double)y + 0.5) * (1.0 / (double)SIZEY))) * angle;
	
	// ray.direction.z = -SIZEY / (2.0 * tan(cam.vfov * 0.5));

	// ray.direction.z = -1.0;

	// ray.direction.x += cam.position.x;
	// ray.direction.y += cam.position.y;
	// ray.direction.z += cam.position.z;
	
	mat_lookat(mat, cam.position, cam.direction);
	ray.direction = mat_multiply_vec(mat, ray.direction);
	ray.direction = vec_normalize(vec_substract(ray.direction, ray.origin));
	return (ray);
}

/* debug */ 
// if ((x == 0 && y == 0) || (x == 1 && y == 0))
// {
// 	printf("\nlookat matrix: \n");
// 	print_matrix(mat);
// }