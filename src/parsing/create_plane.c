/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:39:18 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/15 17:52:40 by cgosseli         ###   ########.fr       */
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
}