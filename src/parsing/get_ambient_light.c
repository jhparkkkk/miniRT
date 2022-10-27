/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_amb_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:46:10 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/26 15:10:40 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static double	get_intens(char *line, int *idx)
{
	double	ret;
	int		j;

	j = 0;
	jump_spaces(line, &j);
	ret = ft_atof(line + j);
	if (check_double(line + j) || ret < 0 || ret > 1.0)
	{
		ft_putstr_fd("Something is wrong with the ambient light intens\n", 2);
		ft_memory(-1, -1);
	}
	jump_data(line, &j);
	(*idx) += j;
	return (ret);
}

static t_amb_light	get_amb_light_specs(char *line)
{
	int				i;
	t_amb_light		amb_light;

	i = 0;
	jump_spaces(line, &i);
	if (!check_elements_nb(3, line))
	{
		ft_putstr_fd("Ambient light: invalid number of elements\n", 2);
		ft_memory(-1, -1);
	}
	i++;
	amb_light.intens = get_intens(line + i, &i);
	amb_light.color = parse_position(line + i, &i);
	if (check_valid_color_range(amb_light.color))
	{
		ft_putstr_fd("Something is wrong with the ambient light color\n", 2);
		ft_memory(-1, -1);
	}
	return (amb_light);
}

/*	checks if ambient light parameter exists and is valid in .rt file
	else prints error and exits
*/
t_amb_light	get_amb_light(char **scene)
{
	int				i;
	int				j;
	int				nb;
	t_amb_light		amb_light;

	i = -1;
	j = 0;
	nb = 0;
	while (scene[++i])
	{
		jump_spaces(scene[i], &j);
		if (scene[i][j] && scene[i][j] == 'A'
			&& ((scene[i][j + 1] >= 9 && scene[i][j + 1] <= 13)
			|| scene[i][j + 1] == 32))
		{
			nb++;
			amb_light = get_amb_light_specs(scene[i]);
		}
	}	
	if (nb != 1)
	{
		ft_putstr_fd("The scene can contain only one ambient light\n", 2);
		ft_memory(-1, -1);
	}
	return (amb_light);
}
