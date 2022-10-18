/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_lookat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:05:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/17 19:01:53 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void    inverse_matrix(double m[4][4], double r[4][4], t_vec3 from)
{
    (void)from;
    r[0][0] = m[0][0];
    r[0][1] = m[1][0];
    r[0][2] = m[2][0];
    
    // r[0][3] = from.x;
    r[0][3] = 0.0f;
    r[1][0] = m[0][1];
    r[1][1] = m[1][1];
    r[1][2] = m[2][1];
    // r[1][3] = from.y;

    r[1][3] = 0.0f;
    r[2][0] = m[0][2];
    r[2][1] = m[1][2];
    r[2][2] = m[2][2];
    // r[2][3] = from.z;
    r[2][3] = 0.0f;
    r[3][0] = -(m[3][0] * r[0][0] + m[3][1] * r[1][0] + m[3][2] * r[2][0]);
    r[3][1] = -(m[3][0] * r[0][1] + m[3][1] * r[1][1] + m[3][2] * r[2][1]);
    r[3][2] = -(m[3][0] * r[0][2] + m[3][1] * r[1][2] + m[3][2] * r[2][2]);
    r[3][3] = 1.0f;
    m = r;
}

/* Transforms the positions of the objects within the 3D scene to give
the illusion that they are being viewed from the lens of the camera.
tmp is a random vec to determine where right vector is pointing at */

void    mat_lookat(double mat[4][4], t_vec3 from, t_vec3 to)
{
    t_vec3  forward;
    t_vec3  right;
    t_vec3  up;
    t_vec3  tmp;
    
    forward = to;
    if (to.y > 0.0)
        tmp = vec_init(0.0, 0.0, 1.0);
    else if (to.y < 0.0)
        tmp = vec_init(0.0, 0.0, -1.0);     
    else
        tmp = vec_init(0.0, 1.0, 0.0);
    
    right = vec_cross(forward,tmp);
    up = vec_cross( forward,right);
    
    forward = vec_scalar(forward, -1.0);

    // mat[0][0] = right.x,   mat[0][1] = right.y,   mat[0][2] = right.z,     mat[0][3] = -vec_dot(right, from);
    // mat[1][0] = up.x,      mat[1][1] = up.y,      mat[1][2] = up.z,        mat[1][3] = -vec_dot(up, from);
    // mat[2][0] = forward.x, mat[2][1] = forward.y, mat[2][2] = forward.z,   mat[2][3] = -vec_dot(forward, from);
    // mat[3][0] = 0.0,       mat[3][1] = 0.0,       mat[3][2] = 0.0,         mat[3][3] = 1.0;

    /* maboye */

    mat[0][0] = right.x;   mat[0][1] = up.x,   mat[0][2] = forward.x,   mat[0][3] = from.x;
    mat[1][0] = right.y,   mat[1][1] = up.y,   mat[1][2] = forward.y,   mat[1][3] = from.y;
    mat[2][0] = right.z,   mat[2][1] = up.z,   mat[2][2] = forward.z,   mat[2][3] = from.z;
    mat[3][0] = from.x,    mat[3][1] = from.y, mat[3][2] = from.z,      mat[3][3] = 1.0;
   
    /* j'ai l'impression que reverse ne change rien, je laisse au cas ou*/
    
    // double r[4][4];
    // inverse_matrix(mat, r, from);

    /* debug */
    // print_matrix(mat);
}