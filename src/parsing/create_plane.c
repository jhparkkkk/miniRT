/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:39:18 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/16 17:00:19 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	create_plane(char *data, t_object *plane)
{
	int			i;

	i = 0;

	plane->type = PLANE;
	plane->center = parse_position(data + i, &i);
	plane->direction = parse_direction(data + i, &i);
	plane->color = parse_position(data + i, &i);
	if (check_valid_color_range(plane->color))
	{
		ft_putstr_fd("Something is wrong with the plane color\n", 2);
		ft_memory(0, 0);
	}
}
