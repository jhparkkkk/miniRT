/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_viewport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:48:21 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/04 14:02:01 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_viewport	get_viewport(t_cam cam)
{
	t_viewport	viewport;
	double		aspect_ratio;
	double		theta;
	double		h;
	double		viewport_height;
	double		viewport_width;
	double		focal_length = 1.0;

	aspect_ratio = 16.0/9.0;
	theta = degrees_to_radians(cam.vfov);
	h = tan(theta/2);
	viewport_height = 2.0 * h;
	viewport_width = aspect_ratio * viewport_height;
	
	viewport.horizontal = vec_init(viewport_width, 0.0, 0.0);
	viewport.vertical = vec_init(0.0, viewport_height, 0.0);
	viewport.lower_left_corner = vec_substract(cam.position, vec_scalar(viewport.horizontal, 0.5));
	viewport.lower_left_corner = vec_substract(viewport.lower_left_corner, vec_scalar(viewport.vertical, 0.5));
	viewport.lower_left_corner = vec_substract(viewport.lower_left_corner, vec_init(0.0, 0.0, focal_length));
	return (viewport);
}