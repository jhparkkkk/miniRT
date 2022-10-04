/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:38:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/02 14:43:08 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"


static void	compute_camera_ray(t_ray *ray, double n_i, double n_j, t_vec3 cam_right, t_vec3 cam_up, t_vec3 cam_pos, t_vec3 cam_dir)
{
	t_vec3	image_point;

	cam_right = vec_scalar(cam_right, n_j);
	cam_up = vec_scalar(cam_up, n_i);
	
	image_point = vec_add(cam_right, cam_up);
	image_point = vec_add(image_point, cam_pos);
	image_point = vec_add(image_point, cam_dir);
	
	ray->direction = vec_substract(image_point, cam_pos);
	ray->direction = vec_normalize(ray->direction);

}

/* Calculates the color of each pixel on the window depending on the objects
in the world. Put the image to the window and launch the mlx. */
void    draw_world(t_world *world, t_mlx *mlx)
{
	int		i;
	int		j;
	t_ray	ray;
	int		obj_idx;
    i = 0;
	(void)world;

	/* CAMERA */ 
	double	normalized_i;
	double	normalized_j;
	t_vec3	camera_position;
	t_vec3	camera_direction;
	t_vec3	camera_right;
	t_vec3	camera_up;

	camera_position = world->cam.position;
	
	camera_direction = vec_substract(world->cam.direction, camera_position);
	camera_direction = vec_normalize(camera_direction);

	camera_right = vec_cross(vec_init(0.0, 1.0, 0.0), camera_direction);
	
	camera_up = vec_cross(camera_right, camera_direction);

	
	double half_width = SIZEX * 0.5;
	double half_height = SIZEY * 0.5;
	
    while (i < SIZEY)
	{
		j = 0;
		while (j <= SIZEX)
		{
			
			normalized_j = half_width + (half_width - (-half_width)) * (j + 0.5) / SIZEX;
			normalized_i = half_height + (half_height - (-half_height)) * (i + 0.5) / SIZEY;
			

			compute_camera_ray(&ray, normalized_i, normalized_j, camera_right, camera_up, camera_position, camera_direction);
			// set_ray(&ray, world->cam, i, j);
			obj_idx = hit_obj(&ray, world);
			if (obj_idx >= 0)
			{
				put_pix(mlx, j, i, compute_color(&ray, world->objects[obj_idx], world));
			}
			j++;
		}
		i++;
	}
    mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
    mlx_loop(mlx->ptr);
}