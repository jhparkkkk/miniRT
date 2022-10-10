/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/10 17:50:00 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vec3	mat_multiply_vec(double mat[4][4], t_vec3 vec)
{
	t_vec3 res;

	res.x = mat[0][0] * vec.x + mat[0][1] * vec.y + mat[0][2] * vec.z + mat[0][3];
	res.y = mat[1][0] * vec.x + mat[1][1] * vec.y + mat[1][2] * vec.z + mat[1][3];
	res.z = mat[2][0] * vec.x + mat[2][1] * vec.y + mat[2][2] * vec.z + mat[2][3];
	
	return (res);
}

t_ray	set_ray(t_cam cam, int x, int y, double mat[4][4])
{
	t_ray	ray;
	
	double imageAspectRatio = (double)SIZEX / (double)SIZEY;  //assuming width > height 
	double angle = tan((0.5 * cam.hfov) * (M_PI / 180.0)); 
	double Px = (2.0 * (((double)x + 0.5) * (1.0 / (double)SIZEX)) - 1) * angle * imageAspectRatio; 
	double Py = (1.0 - 2.0 * (((double)y + 0.5) * (1.0 / (double)SIZEY))) * angle;

	ray.origin = cam.position;

	ray.direction.x = -Px;
	ray.direction.y = -Py;
	ray.direction.z = -1.0;
	// ray.direction = vec_normalize(ray.direction);
	
	mat_lookat(mat, ray.origin, ray.direction);
	

	if ((x == 0 && y == 0) || (x == 1 && y == 0))
    {
		printf("\nrotation matrix\n");
		int i;
    	int j;
		i = 0;
    	while(i < 4)
    	{
    	    j = 0;
    	    while(j < 4)
    	    {
    	        printf("%f  ", mat[i][j]);
    	        j++;
    	    }
    	    printf("\n");
    	    i++;
    	}
	}
	// ray.direction = vec_substract(ray.direction, ray.origin);
	
	ray.direction = mat_multiply_vec(mat, ray.direction);
	// ray.direction = vec_normalize(ray.direction);
	
	return (ray);
}
