/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:55:39 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/27 18:44:18 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/* sous fonction pour la surface si on ajoute la specular
   Attention il faudra modifier le checker d'arguments
*/
static void	get_sphere_surface(t_object *sphere, char *data, int i)
{
	sphere->surface = get_surface(data + i, &i);
	if (sphere->surface == SHINY)
	{
		sphere->specular_exponent = get_specular_exponent(data + i, &i);
		sphere->k_spec = 10.0;
	}
	else
	{
		sphere->specular_exponent = 0.1;
		sphere->k_spec = 0.0;
	}	
}

static double	get_radius(char *data, int *idx)
{
	double	ret;
	int		j;

	j = 0;
	jump_spaces(data, &j);
	ret = ft_atof(data + j);
	if (check_double(data + j) || ret <= 0)
	{
		ft_putstr_fd("Something is wrong with the sphere\n", 2);
		ft_memory(-1, -1);
	}
	while (data[j] && !(data[j] == 32 || (data[j] >= 9 && data[j] <= 13)))
		j++;
	(*idx) += j;
	return (ret / 2);
}

/*
	Gets all parameters needed to create sphere in the world space
*/
void	create_sphere(char *data, t_object *sphere)
{
	int	i;

	i = 0;
	if (!check_elements_nb(3, data))
	{
		ft_putstr_fd("Sphere: inavlid number of elements\n", 2);
		ft_memory(-1, -1);
	}
	sphere->type = SPHERE;
	sphere->center = parse_position(data + i, &i);
	sphere->radius = get_radius(data + i, &i);
	sphere->color = parse_position(data + i, &i);
	if (check_valid_color_range(sphere->color))
	{
		ft_putstr_fd("Something is wrong with the sphere color\n", 2);
		ft_memory(-1, -1);
	}
	sphere->intersect = hit_sp;
	sphere->print_object = &print_sp;
	get_sphere_surface(sphere, data, i);
}
