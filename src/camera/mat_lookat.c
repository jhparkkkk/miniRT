/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_lookat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:05:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/26 13:20:08 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"



/* Transforms the positions of the objects within the 3D scene to give
the illusion that they are being viewed from the lens of the camera.
tmp is a random vec to determine where right vector is pointing at */

void	mat_lookat(double mat[4][4], t_vec3 from, t_vec3 to)
{
    t_vec3  forward;
    t_vec3  right;
    t_vec3  up;
    t_vec3  tmp;
    
    forward = to;
    if ((to.x == 0 && to.y == 1 && to.z == 0) || (to.x == 0 && to.y == -1 && to.z == 0))
        tmp = vec_init(1.0, 0.0, 0.0);
    else
        tmp = vec_init(0.0, 1.0, 0.0);
    
    right = vec_cross(tmp, forward);
    up = vec_cross( forward,right);
    
    forward = vec_scalar(forward, -1.0);

    mat[0][0] = right.x;   mat[0][1] = up.x,   mat[0][2] = forward.x,   mat[0][3] = from.x;
    mat[1][0] = right.y,   mat[1][1] = up.y,   mat[1][2] = forward.y,   mat[1][3] = from.y;
    mat[2][0] = right.z,   mat[2][1] = up.z,   mat[2][2] = forward.z,   mat[2][3] = from.z;
    mat[3][0] = from.x,    mat[3][1] = from.y, mat[3][2] = from.z,      mat[3][3] = 1.0;

}