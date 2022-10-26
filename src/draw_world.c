/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:38:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/25 19:26:53 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"
#include <math.h>

/* Calculates the color of each pixel on the window depending on the objects
in the world. Put the image to the window and launch the mlx. */
void    draw_world(t_world *world, t_mlx *mlx)
{
	double		y;
	double		x;
	t_ray	ray;
	int		obj_idx;
	double	lookat[4][4];
    y = 0;
	(void)world;

	
    while (y < (double)SIZEY)
	{
		x = 0;
		while (x <= (double)SIZEX)
		{
			ray = set_ray(world->cam, x, y, lookat);
			obj_idx = hit_obj(&ray, world, __DBL_EPSILON__, INFINITY, 0);
			if (obj_idx >= 0)
			{
				put_pix(mlx, (int)x, (int)y, compute_color(&ray, world->objects[obj_idx], world));
			}
			x++;
		}
		y++;
	}
	printf("done\n");
    mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 17, 1L << 17, press_mouse, world);
	
    mlx_loop(mlx->ptr);
}