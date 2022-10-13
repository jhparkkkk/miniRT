/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/13 13:31:19 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_ray	set_ray(t_cam cam, int x, int y, double mat[4][4])
{
	t_ray	ray;
	double	aspect_ratio; 
	double	angle;

	/* projection */
	aspect_ratio = SIZEX / SIZEY;
	angle = tan((0.5 * cam.hfov) * (M_PI / 180.0));
	ray.origin = cam.position;
	ray.direction.x = -((2.0 * (((double)x + 0.5) * (1.0 / (double)SIZEX)) - 1) * angle * aspect_ratio); 
	ray.direction.y = -((1.0 - 2.0 * (((double)y + 0.5) * (1.0 / (double)SIZEY))) * angle);
	ray.direction.z = -1.0;
	
	/* rotation + translation */
	mat_lookat(mat, cam.position, cam.direction);
	ray.direction = mat_multiply_vec(mat, ray.direction);
	return (ray);
}

/* debug */ 
// if ((x == 0 && y == 0) || (x == 1 && y == 0))
// {
// 	printf("\nlookat matrix: \n");
// 	print_matrix(mat);
// }