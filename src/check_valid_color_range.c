/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_color_range.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:23:45 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/14 13:30:43 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/*Returns 1 if the color is less than 0 or more than 255. Else, returns 0*/
int	check_valid_color_range(t_vec3 color)
{
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255
		|| color.z < 0 || color.z > 255)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
