/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:38:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/26 14:39:25 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int    compute_color(t_ray *ray, t_object *object, t_world *world)
{
    double    intensity;
    t_vec3    color;
    // t_vec3    light_color;
    
    intensity = compute_lighting(ray, object, world);
    color = vec_scalar(object->color, intensity);
    // light_color = get_hex_color(world->light.color);
    // light_color = vec_scalar(world->ambient_light.color, world->ambient_light.intensity);
    // light_color = vec_scalar(light_color, 0.5);
    // color = vec_add(color, light_color);
    // color = vec_add(color, world->)
    return get_hex_color(color);
}

void	set_ray(t_ray *ray, t_cam cam, int i, int j)
{
	ray->origin = cam.position;
	ray->direction.x = j - SIZEX / 2;
	ray->direction.y = i - SIZEY / 2;
	ray->direction.z = -10.0;
	ray->direction = vec_add(ray->direction, cam.direction);

}


void    draw_world(t_world *world, t_mlx *mlx)
{
	int	i;
	int	j;
	t_ray ray;
	int	obj_idx;
	// double intensity = 0;
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
				// intensity = compute_lighting(&ray, world->objects[obj_idx], world);
				put_pix(mlx, j, i, compute_color(&ray, world->objects[obj_idx], world));
				// put_pix(mlx, j, i, get_hex_color(vec_scalar(world->objects[obj_idx]->color, intensity)));
			}
			j++;
		}
		i++;
	}
    mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
    mlx_loop(mlx->ptr);
}