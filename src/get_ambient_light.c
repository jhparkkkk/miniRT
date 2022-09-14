/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ambient_light.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:46:10 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/14 13:52:10 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static float	get_intensity(char *line, int *idx)
{
	float	ret;
	int		j;

	j = 0;
	while (line[j] && (line[j] == 32 || (line[j] >= 9 && line[j] <= 13)))
		j++;
	ret = ft_atof(line + j);
	
	if (check_float(line + j) || ret < 0 || ret > 180.0)
	{
		ft_putstr_fd("Something is wrong with the ambient light intensity\n", 2);
		ft_memory(0, 0);
	}
	while (line[j] && !(line[j] == 32 || (line[j] >= 9 && line[j] <= 13)))
		j++;
	(*idx) += j;
	return (ret);
}

static t_ambient_light	get_ambient_light_specs(char *line)
{
	int		i;
	t_ambient_light	ambient_light;

	i = 0;
	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	i++;
	ambient_light.intensity = get_intensity(line + i, &i);
	ambient_light.color = parse_position(line + i, &i);
	if (check_valid_color_range(ambient_light.color))
	{
		ft_putstr_fd("Something is wrong with the ambient light color\n", 2);
		ft_memory(0, 0);
	}
	return (ambient_light);
}

t_ambient_light	get_ambient_light(char **scene)
{
	int				i;
	int				j;
	int				nb;
	t_ambient_light	ambient_light;

	i = -1;
	j = 0;
	nb = 0;
	while (scene[++i])
	{
		while (scene[i] && (scene[i][j] == 32 || (scene[i][j] >= 9
			&& scene[i][j] <= 13)))
			j++;
		if (scene[i][j] && scene[i][j] == 'A')
		{
			nb++;
			ambient_light = get_ambient_light_specs(scene[i]);
		}
	}	
	if (nb > 1)
	{
		ft_putstr_fd("The scene can contain only one ambient light\n", 2);
		ft_memory(0, 0);
	}
	return (ambient_light);
}