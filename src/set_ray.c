/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/05 18:41:59 by jeepark          ###   ########.fr       */
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
	
	ray.origin = cam.position;
	ray.direction.x = (double)x - (double)SIZEX / 2.0;
	ray.direction.y = (double)y - (double)SIZEY / 2.0;
	ray.direction.z = -10.0;

	// ray.direction.x = (double)x ;
	// ray.direction.y = (double)y ;
	// ray.direction.z = -10.0;

	// ray.direction = mat_multiply_vec(cam.mat_projection, ray.direction);
	
	ray.direction = vec_substract(ray.direction, cam.direction);
	
	
	ray.direction = vec_normalize(ray.direction);
	
	return (ray);
}