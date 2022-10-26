/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_multiply_vec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:40:37 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/25 19:30:32 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vec3	mat_multiply_vec(double mat[4][4], t_vec3 vec)
{
	t_vec3	res;

	res.x = mat[0][0] * vec.x + mat[0][1] * vec.y + mat[0][2] * vec.z
		+ mat[0][3];
	res.y = mat[1][0] * vec.x + mat[1][1] * vec.y + mat[1][2] * vec.z
		+ mat[1][3];
	res.z = mat[2][0] * vec.x + mat[2][1] * vec.y + mat[2][2] * vec.z
		+ mat[2][3];
	return (res);
}
