/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:38:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/25 17:48:35 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	set_ray(t_ray *ray, t_cam cam, int i, int j)
{
	ray->origin = cam.position;
	ray->direction.x = j - SIZEX / 2;
	ray->direction.y = i - SIZEY / 2;
	ray->direction.z = -10.0;
	ray->direction = vec_add(ray->direction, cam.direction);

}

double	compute_lighting(t_ray *ray, t_object *sp, t_world *world)
{
	t_vec3 point;
	t_vec3 normal;
	t_vec3 vec_light;
	double intensity;
	double n_dot_l;
	
	intensity = 0.0;
	intensity += world->ambient_light.intensity;
	point = vec_add(ray->origin, vec_scalar(ray->direction, ray->root));
	normal = vec_substract(point, sp->center);
	normal = vec_divide(normal, vec_len(normal));
	
	
	vec_light = vec_substract(world->light.position, point);
	
	n_dot_l = vec_dot(normal, vec_light);
	if (n_dot_l > 0.0)
		intensity += world->light.intensity * n_dot_l / (vec_len(normal) * vec_len(vec_light)); 
	return (intensity);
	
}
// TODO : pb avec n_dot_l qui n'est jamais positif / revoir le calcul 

void    draw_world(t_world *world, t_mlx *mlx)
{
	int	i;
	int	j;
	t_ray ray;
	int	obj_idx;
	double intensity = 0;
    i = 0;
	(void)world;
	
	// get_background_color(world->ambient_light);
    while (i < SIZEY)
	{
		j = 0;
		while (j <= SIZEX)
		{
			set_ray(&ray, world->cam, i, j);
			obj_idx = hit_obj(&ray, world);
			if (obj_idx >= 0)
			{
				intensity = compute_lighting(&ray, world->objects[obj_idx], world);
				put_pix(mlx, j, i, get_hex_color(vec_scalar(world->objects[obj_idx]->color, intensity)));
			}
			j++;
		}
		i++;
	}
    mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
    mlx_loop(mlx->ptr);
}