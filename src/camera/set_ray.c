/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/26 15:11:36 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/* transforms direction of each ray generated from camera. vec direction depends
   on projection + rortation + translation opertion.
   Returns calculated ray from the camera to each pixel of the screen 
*/
t_ray	set_ray(t_cam cam, int x, int y, double mat[4][4])
{
	t_ray	ray;
	double	aspect_ratio;
	double	angle;

	aspect_ratio = (double)SIZEX / (double)SIZEY;
	angle = cam.hfov * M_PI / 180.0;
	ray.origin = cam.position;
	ray.direction.x = (2.0 * (((double)x + 0.5) * (1.0 / (double)SIZEX)) - 1)
		* tan(angle * 0.5) * aspect_ratio;
	ray.direction.y = (1.0 - 2.0 * (((double)y + 0.5) * (1.0 / (double)SIZEY)))
		* tan(angle * 0.5);
	ray.direction.z = -1.0;
	mat_lookat(mat, cam.position, cam.direction);
	ray.direction = mat_multiply_vec(mat, ray.direction);
	ray.direction = vec_normalize(vec_substract(ray.direction, ray.origin));
	return (ray);
}
