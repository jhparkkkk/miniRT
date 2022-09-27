/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:51:05 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/27 17:56:19 by jeepark          ###   ########.fr       */
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
	intensity = compute_lighting(ray, object, world);
	
	
	
	color_2 = vec_add(object->color, vec_scalar(world->ambient_light.color, world->ambient_light.intensity));
	color_1 = vec_add(object->color, vec_scalar(world->light.color, intensity));
	color = vec_add(color_1, color_2);

    color = vec_normal(color);
	// color = vec_divide(color, vec_len(color));
	color = vec_scalar(color, 255.0);
	
	return get_hex_color(color);
}