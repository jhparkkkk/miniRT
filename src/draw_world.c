/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:38:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/24 15:08:17 by cgosseli         ###   ########.fr       */
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

void	set_ray(t_ray *ray, int i, int j)
{
	// t_vec3 h_vec;
	// t_vec3 v_vec;
	// t_vec3 focal_vec;
	// t_vec3 etape_1;
	// t_vec3 etape_2;
	// t_vec3 etape_3;
	// t_vec3 etape_4;
	// t_vec3 etape_5;
	// float	u;
	// float	v;
	
	// h_vec.x = SIZEX;
	// h_vec.y = 0;
	// h_vec.z = 0;
	// v_vec.x = 0;
	// v_vec.y = SIZEY;
	// v_vec.z = 0;
	// focal_vec.x = 0;
	// focal_vec.y = 0;
	// focal_vec.z = 1;
	
	ray->origin.x = 0;
	ray->origin.y = 0;
	ray->origin.z = 0;
	
	// // get_ray_direction()
	// etape_1 = vec_substract(ray->origin, vec_scalar(h_vec, 0.5));
	// etape_2 = vec_substract(vec_scalar(v_vec, 0.5), focal_vec);
	// etape_3 = vec_substract(etape_1, etape_2);
	// u = i / (SIZEY -1);
	// v = j / (SIZEX -1);
	
	// etape_4 = vec_add(etape_3, vec_scalar(v_vec, u));
	// etape_5 = vec_substract(vec_scalar(h_vec, v), ray->origin);
	// ray->direction = vec_add(etape_4, etape_5);
	
	ray->direction.x = j - SIZEX / 2;
	ray->direction.y = i - SIZEY / 2;
	ray->direction.z = 1.0;

}

void    draw_world(t_world *world, t_mlx *mlx)
{
	int	i;
	int	j;
	unsigned int color;
	t_vec3 rgb_color;
	t_ray ray;
	rgb_color.x = 255;
	rgb_color.y = 0;
	rgb_color.z = 0;
	color = get_hex_color(rgb_color);
    i = 0;
	(void)world;
	
	// get_background_color(world->ambient_light);
    while (i < SIZEY)
	{
		j = 0;
		printf("\n");
		while (j <= SIZEX)
		{
			set_ray(&ray, i, j);
			if (hit_sp(&ray, world, world->objects[0]))
			{
				put_pix(mlx, j, i, color);
				printf("8");
			}
			else
				printf(".");
			// if (i + 1 < SIZEY)
			// 	put_pix(mlx, j, i, color);
			// if (j + 1 <= SIZEX)
			// 	put_pix(mlx, j, i, color);
			j++;
		}
		i++;
	}
    mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
    mlx_loop(mlx->ptr);
}