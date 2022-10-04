/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/04 18:17:12 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vec3 vec_mat_multiply(t_vec3 vec, double **mat)
{
	t_vec3	vec_res;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			
		}
	}	
}

t_ray	set_ray(t_cam cam, int x, int y, t_viewport viewport)
{
	t_ray	ray;
	
	double imageAspectRatio = (double)SIZEX / (double)SIZEY;
    double Px = (2.0 * ((x + 0.5) / (double)SIZEX) - 1.0) * tan(cam.vfov / 2.0 * M_PI / 180.0) * imageAspectRatio; 
    double Py = (1.0 - 2.0 * ((y + 0.5) / (double)SIZEY) * tan(cam.vfov / 2.0 * M_PI / 180.0));
	
	ray.origin = cam.position;
	
	ray.direction = vec_mat_multiply(vec_init(Px, Py, -1), cam.lookat);
	
	ray.direction = vec_normalize(ray.direction);
	
	return (ray);
}