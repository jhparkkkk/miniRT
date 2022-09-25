/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:53:12 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/25 16:40:03 by jeepark          ###   ########.fr       */
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
		ft_memory(0, 0);
	}
	while (data[j] && !(data[j] == 32 || (data[j] >= 9 && data[j] <= 13)))
		j++;
	(*idx) += j;
	return (ret);
}

void	create_cylinder(char *data, t_object *cylinder)
{
	int	i;

	i = 0;
	cylinder->type = CYLINDER;
	cylinder->center = parse_position(data + i, &i);
	cylinder->direction = parse_direction(data + i, &i);
	cylinder->radius = get_double(data + i, &i) / 2;
	cylinder->height = get_double(data + i, &i);
	cylinder->color = parse_position(data + i, &i);
	if (check_valid_color_range(cylinder->color))
	{
		ft_putstr_fd("Something is wrong with the cylinder color\n", 2);
		ft_memory(0, 0);
	}
}