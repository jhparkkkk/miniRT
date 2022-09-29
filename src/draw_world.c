/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:38:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/29 13:46:06 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	compute_color(t_ray *ray, t_object *object, t_world *world)
{
	double	intensity;
	t_vec3	color;
	
	intensity = compute_lighting(ray, object, world);
	t_vec3 light_1 = vec_scalar(world->light.color, intensity * K_DIFFUSE);
	t_vec3 light_2 = vec_scalar(world->ambient_light.color, world->ambient_light.intensity * K_AMBIENT);
	t_vec3 light_global = vec_add(light_1, light_2);
	t_vec3 ambient_to_obj = vec_scalar(object->color, world->ambient_light.intensity * K_AMBIENT);
	t_vec3 light_to_obj = vec_scalar(object->color, intensity * K_DIFFUSE);
	color = vec_add(light_to_obj, ambient_to_obj);
	color = vec_add(color, light_global);
	return get_hex_color(color);
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