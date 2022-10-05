/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:38:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/05 16:16:33 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <math.h>
/* Calculates the color of each pixel on the window depending on the objects
in the world. Put the image to the window and launch the mlx. */
void    draw_world(t_world *world, t_mlx *mlx)
{
	int		y;
	int		x;
	t_ray	ray;
	int		obj_idx;
    y = 0;
	(void)world;
	
	double rad = degrees_to_radians(50.0);
	double distance = (SIZEX * 0.5) * (1.0 * tan(rad));
	ray.origin.x = SIZEY * 0.5;
	ray.origin.y = SIZEX * 0.5;
	ray.origin.z = -distance;
	
    while (y < SIZEY)
	{
		x = 0;
		while (x <= SIZEX)
		{
			ray = set_ray(world->cam, x, y);
			obj_idx = hit_obj(&ray, world);
			if (obj_idx >= 0)
			{
				put_pix(mlx, x, y, compute_color(&ray, world->objects[obj_idx], world));
			}
			x++;
		}
		y++;
	}
	printf("done\n");
    mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
    mlx_loop(mlx->ptr);
}