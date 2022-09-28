/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:51:05 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/28 10:56:36 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	compute_color(t_ray *ray, t_object *object, t_world *world)
{
	double	intensity;
	t_vec3  color[world->nb_light + 1];
    t_vec3  res_color;
    // t_vec3	color_1;
	// t_vec3	color_2;
	// t_vec3	color; 
	intensity = compute_lighting( world->light[1], ray, object);
	
	
	
	color[0] = vec_add(object->color, vec_scalar(world->ambient_light.color, world->ambient_light.intensity));
	color[1] = vec_add(object->color, vec_scalar(world->light[1]->color, intensity));
	res_color = vec_add(color[0], color[1]);

    res_color = vec_normal(res_color);
	// res_color = vec_divide(res_color, vec_len(res_color));
	res_color = vec_scalar(res_color, 255.0);
	
	return get_hex_color(res_color);
}