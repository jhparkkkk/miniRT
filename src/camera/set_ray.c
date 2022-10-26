/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/25 19:48:35 by jeepark          ###   ########.fr       */
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
	angle = cam.hfov * M_PI / 180.0;
	ray.origin = cam.position;
	ray.direction.x = (2.0 * (((double)x + 0.5) * (1.0 / (double)SIZEX)) - 1) * tan(angle * 0.5) * aspect_ratio;
	ray.direction.y = (1.0 - 2.0 * (((double)y + 0.5) * (1.0 / (double)SIZEY))) * tan(angle * 0.5);
	ray.direction.z = -1.0;

	/* rotation + translation avec lookat matrix */
	mat_lookat(mat, cam.position, cam.direction);
	ray.direction = mat_multiply_vec(mat, ray.direction);
	ray.direction = vec_normalize(vec_substract(ray.direction, ray.origin));
	
	return (ray);
}


	