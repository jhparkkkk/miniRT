/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_lookat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:05:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/26 14:53:37 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	put_last_row(double *mat)
{
	mat[0] = 0.0;
	mat[1] = 0.0;
	mat[2] = 0.0;
	mat[3] = 1.0;
}

/* Transforms the positions of the objects within the 3D scene to give
   the illusion that they are being viewed from the lens of the camera.
   tmp is a random vec to determine where right vector is pointing at */

void	mat_lookat(double mat[4][4], t_vec3 from, t_vec3 to)
{
	t_vec3	right;
	t_vec3	up;
	t_vec3	tmp;

	if ((to.x == 0 && to.y == 1 && to.z == 0)
		|| (to.x == 0 && to.y == -1 && to.z == 0))
		tmp = vec_init(1.0, 0.0, 0.0);
	else
		tmp = vec_init(0.0, 1.0, 0.0);
	right = vec_cross(tmp, to);
	up = vec_cross(to, right);
	to = vec_scalar(to, -1.0);
	mat[0][0] = right.x;
	mat[0][1] = up.x;
	mat[0][2] = to.x;
	mat[0][3] = from.x;
	mat[1][0] = right.y;
	mat[1][1] = up.y;
	mat[1][2] = to.y;
	mat[1][3] = from.y;
	mat[2][0] = right.z;
	mat[2][1] = up.z;
	mat[2][2] = to.z;
	mat[2][3] = from.z;
	put_last_row(mat[3]);
}
