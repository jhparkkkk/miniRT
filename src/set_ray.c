/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:16:54 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/26 11:55:12 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	set_ray(t_ray *ray, t_cam cam, int i, int j)
{
	ray->origin = cam.position;
	ray->direction.x = j - SIZEX / 2;
	ray->direction.y = i - SIZEY / 2;
	ray->direction.z = -10.0;
	ray->direction = vec_add(ray->direction, cam.direction);

}