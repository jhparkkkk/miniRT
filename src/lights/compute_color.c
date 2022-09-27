/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:51:05 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/27 20:48:10 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int check_rgb_value(t_vec3 color)
{
    if (color.x > 255.0 || color.y > 255.0 || color.z > 255.0)
        return (1);
    return (0);
}

int	compute_color(t_ray *ray, t_object *object, t_world *world)
{
	double	intensity;
	t_vec3	ambient;
	t_vec3	spot;
	t_vec3	color;

    
	intensity = compute_lighting(ray, object, world);
	
	// normalise
	
	ambient = vec_add(object->color, vec_scalar(world->ambient_light.color, world->ambient_light.intensity));
	spot = vec_add(object->color, vec_scalar(world->light.color, intensity));
    
    color = vec_add(ambient, spot);

    if (check_rgb_value(color))
    {
        color = vec_normal(color);
	    color = vec_scalar(color,  255.0);
    }
	return get_hex_color(color);
}