/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:38:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/22 18:16:46 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void    draw_world(t_world *world, t_mlx *mlx)
{
	int	i;
	int	j;
	unsigned int color;
	t_vec3 rgb_color;
	
	rgb_color.x = 255;
	rgb_color.y = 100;
	rgb_color.z = 100;
	color = get_hex_color(rgb_color);
    i = 0;
	(void)world;
	// get_background_color(world->ambient_light);
    while (i < HEIGHT)
	{
		j = 0;
		while (j <= WIDTH)
		{
			if (i + 1 < HEIGHT)
				put_pix(mlx, j, i, color);
			if (j + 1 <= WIDTH)
				put_pix(mlx, j, i, color);
			j++;
		}
		i++;
	}
    mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
    mlx_loop(mlx->ptr);
}