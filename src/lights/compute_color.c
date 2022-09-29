/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:51:05 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/29 10:45:37 by jeepark          ###   ########.fr       */
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
	double	intensity_spot;
	double	intensity_ambient;
	
	t_vec3	color_spot;
	t_vec3	color_ambient;
	
	t_vec3	color;
	
	intensity_spot = compute_lighting(ray, object, world);
	intensity_ambient = world->ambient_light.intensity;

	color_spot = vec_scalar(object->color, intensity_spot);
	color_ambient = vec_scalar(object->color, intensity_ambient);
	
	color = vec_add(color_spot, color_ambient);
	

	return get_hex_color(color);
}