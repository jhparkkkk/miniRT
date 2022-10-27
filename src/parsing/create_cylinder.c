/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:53:12 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/27 18:44:03 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static double	get_double(char *data, int *idx)
{
	double	ret;
	int		j;

	j = 0;
	jump_spaces(data, &j);
	ret = ft_atof(data + j);
	if (check_double(data + j) || ret <= 0)
	{
		ft_putstr_fd("Something is wrong with the cylinder\n", 2);
		ft_memory(-1, -1);
	}
	while (data[j] && !(data[j] == 32 || (data[j] >= 9 && data[j] <= 13)))
		j++;
	(*idx) += j;
	return (ret);
}

/*
	Gets all parameters needed to create cylinder in the world space
*/
void	create_cylinder(char *data, t_object *cylinder)
{
	int	i;

	i = 0;
	if (!check_elements_nb(5, data))
	{
		ft_putstr_fd("Cylinder: invalid number of elements\n", 2);
		ft_memory(-1, -1);
	}
	cylinder->type = CYLINDER;
	cylinder->center = parse_position(data + i, &i);
	cylinder->dir = parse_dir(data + i, &i);
	cylinder->dir = vec_normalize(cylinder->dir);
	cylinder->radius = get_double(data + i, &i) / 2;
	cylinder->height = get_double(data + i, &i);
	cylinder->color = parse_position(data + i, &i);
	if (check_valid_color_range(cylinder->color))
	{
		ft_putstr_fd("Something is wrong with the cylinder color\n", 2);
		ft_memory(-1, -1);
	}
	cylinder->surface = get_surface(data + i, &i);
	cylinder->intersect = hit_cy;
	cylinder->print_object = &print_cy;
}
