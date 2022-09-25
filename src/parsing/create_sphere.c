/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:55:39 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/25 13:21:34 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static float	get_radius(char *data, int *idx)
{
	float	ret;
	int		j;

	j = 0;
	jump_spaces(data, &j);
	ret = ft_atof(data + j);
	printf("data %s\n", data + j);

	printf("ret %f\n", ret);
	if (check_float(data + j) || ret <= 0)
	{
		ft_putstr_fd("Something is wrong with the sphere\n", 2);
		ft_memory(0, 0);
	}
	while (data[j] && !(data[j] == 32 || (data[j] >= 9 && data[j] <= 13)))
		j++;
	(*idx) += j;
	return (ret / 2);
}

void	create_sphere(char *data, t_object *sphere)
{
	int			i;

	i = 0;

	sphere->type = SPHERE;
	sphere->center = parse_position(data + i, &i);
	sphere->radius = get_radius(data + i, &i);
	sphere->color = parse_position(data + i, &i);
	if (check_valid_color_range(sphere->color))
	{
		ft_putstr_fd("Something is wrong with the sphere color\n", 2);
		ft_memory(0, 0);
	}
	sphere->intersect = hit_sp;
	sphere->print_object = &print_sp;
}