/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:38:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/25 14:02:43 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

// static t_vec3 get_lower_left_corner

// static t_vec3 get_ray_direction()
// {
// 	t_vec3 lower_left_corner; 
	 
// 	lower_left_corner = get_lower_left_corner()
// 	return (direction);
// }

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
				put_pix(mlx, j, i, get_hex_color(world->objects[obj_idx]->color));
			j++;
		}
		i++;
	}
    mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
    mlx_loop(mlx->ptr);
}