/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:38:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/26 16:30:52 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	compute_color(t_ray *ray, t_object *object, t_world *world)
{
	double	intensity;
	t_vec3	color;
	t_vec3 light_color;
	intensity = compute_lighting(ray, object, world);
	
	light_color = vec_scalar(world->light.color, world->light.intensity);
	
	color = vec_add(object->color, light_color);
	// color = vec_scalar(object->color, intensity);
	return get_hex_color(color);
}

void    draw_world(t_world *world, t_mlx *mlx)
{
	int		i;
	int		j;
	t_ray	ray;
	int		obj_idx;
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
				put_pix(mlx, j, i, compute_color(&ray, world->objects[obj_idx], world));
			}
			j++;
		}
		i++;
	}
    mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
    mlx_loop(mlx->ptr);
}