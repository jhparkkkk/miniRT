/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/12 10:43:29 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void    put_vec(double *mat, t_vec3 vec)
{
    mat[0] = vec.x;
    mat[1] = vec.y;
    mat[2] = vec.z;
    mat[3] = 0.0;
}


static void fill_mat_translation(double mat[4][4], t_vec3 camera_pos)
{
    int i;

    i = 0;
    put_vec(mat[i], vec_init(1.0, 0.0, 0.0));
    put_vec(mat[++i], vec_init(0.0, 1.0, 0.0));
    put_vec(mat[++i], vec_init(0.0, 0.0, 1.0));
    put_vec(mat[++i], vec_init(0.0, 0.0, 0.0));
    
    i = 0;
    mat[i][3] = -camera_pos.x;
    mat[++i][3] = -camera_pos.y;
    mat[++i][3] = -camera_pos.z;
    mat[++i][3] = 1.0;

}

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
	(void)mat;
	t_ray	ray;
	
	double imageAspectRatio = (double)SIZEX / (double)SIZEY;  //assuming width > height 
	double angle = tan((0.5 * cam.hfov) * (M_PI / 180.0)); 
	double Px = (2.0 * (((double)x + 0.5) * (1.0 / (double)SIZEX)) - 1) * angle * imageAspectRatio; 
	double Py = (1.0 - 2.0 * (((double)y + 0.5) * (1.0 / (double)SIZEY))) * angle;

	ray.origin = cam.position;

	ray.direction.x = -Px;
	ray.direction.y = -Py;
	ray.direction.z = -1.0;
	
	ray.direction = vec_normalize(ray.direction);
	
	double mat_translation[4][4];
    fill_mat_translation(mat_translation, cam.position);
	
	if ((x == 0 && y == 0) || (x == 1 && y == 0))
		print_matrix(mat_translation);
		
	ray.direction = mat_multiply_vec(mat_translation, ray.direction);
	ray.direction = vec_normalize(ray.direction);
	

	mat_lookat(mat, cam.position, cam.direction);
		
	ray.direction = vec_substract(ray.direction, ray.origin);
	
	ray.direction = mat_multiply_vec(mat, ray.direction);
	ray.direction = vec_normalize(ray.direction);
	

	return (ray);
}
