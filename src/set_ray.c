/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/09 22:16:38 by jeepark          ###   ########.fr       */
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
	
	double imageAspectRatio = (double)SIZEX / (double)SIZEY;  //assuming width > height 
	double angle = tan(M_PI * 0.5 * cam.hfov / 180.); 
	double Px = (2.0 * ((x + 0.5) * (1.0 / SIZEX)) - 1.0) * angle * imageAspectRatio; 
	double Py = (1.0 - 2.0 * ((y + 0.5) * (1.0 / SIZEY))) * angle;

	ray.origin = cam.position;

	ray.direction.x = Px;
	ray.direction.y = Py;
	ray.direction.z = -1.0;
	
	ray.direction = vec_substract(ray.direction, ray.origin);
	
	ray.direction = vec_normalize(ray.direction);
	
	return (ray);
}

/*
Imaginon un "ECRan" 8 * 6, le point & correspong(<=>)
imaginon, le centre C(xc,yc,zc); ainci que deux vecteur de dirrection
parrelelles a notre plan X(x',y',z') && Y(x'',y'',z'')

& = C - (X * longuer/2) + (Y * longuer/2) <=> C - (X * 8/2) + (Y * 6 / 2)

&x =
&y =
&z =

&#######
########
########
########
########
########

*/