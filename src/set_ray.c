/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/25 16:40:03 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vec3  vec_direction(t_vec3 direction, double i, double j)
{
    direction.x = j - WIDTH / 2;
    direction.y = i - HEIGHT / 2;
    direction.z = 1;
    return (direction);
}

void	set_ray(t_ray *ray, int i, int j)
{

	ray->origin.x = 0;
	ray->origin.y = 0;
	ray->origin.z = 0;
	
	ray->direction = vec_direction(ray->direction, (double)i, (double)j);

}