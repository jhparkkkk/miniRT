/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/02 14:55:04 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	set_ray(t_ray *ray, t_cam cam, int i, int j)
{
	ray->origin = cam.position;
	ray->direction.x = j - SIZEX / 2;
	ray->direction.y = -i + SIZEY / 2;
	ray->direction.z = -1.0;
	ray->direction = vec_substract(ray->direction, ray->origin);
	ray->direction = vec_normalize(ray->direction);
}