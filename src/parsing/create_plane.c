/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:39:18 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/27 18:44:10 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/*
	Gets all parameters needed to create plane in the world space
*/
void	create_plane(char *data, t_object *plane)
{
	int			i;

	i = 0;
	if (!check_elements_nb(3, data))
	{
		ft_putstr_fd("Plane: invalid number of elements\n", 2);
		ft_memory(-1, -1);
	}
	plane->type = PLANE;
	plane->center = parse_position(data + i, &i);
	plane->dir = parse_dir(data + i, &i);
	plane->dir = vec_normalize(plane->dir);
	plane->color = parse_position(data + i, &i);
	if (check_valid_color_range(plane->color))
	{
		ft_putstr_fd("Something is wrong with the plane color\n", 2);
		ft_memory(-1, -1);
	}
	plane->surface = get_surface(data + i, &i);
	plane->intersect = hit_pl;
	plane->print_object = &print_pl;
}
