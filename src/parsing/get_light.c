/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:19:43 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/26 14:08:58 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"


static int	get_param(t_light *light, char *line)
{
	double	ret;
	int		i;

	if (!check_elements_nb(4, line))
	{
		ft_putstr_fd("The light doesn't have the right number of elements\n", 2);
		ft_memory(0, 0);
	}
	i = 0;
	jump_spaces(line, &i);
	i++;
	light->position = parse_position(line + i, &i);
	jump_spaces(line, &i);
	ret = ft_atof(line + i);
	if (check_double(line + i) || ret < 0 || ret > 1.0)
	{
		ft_putstr_fd("Something is wrong with the light intensity\n", 2);
		ft_memory(0, 0);
	}
	light->intensity = ret;
	jump_data(line, &i);
	light->color = parse_position(line + i, &i);
	return 0;
}

/*	checks if light parameter exists and is valid in .rt file
	else prints error and exits
*/
int get_light(t_light *light, char **scene)
{
	int i;
	int j;
	int nb;
	
	nb = 0;
	i = -1;
    while (scene[++i])
	{
		j = 0;
		jump_spaces(scene[i], &j);
		if (scene[i][j] == 'L'
			&& ((scene[i][j + 1] >= 9 && scene[i][j + 1] <= 13) || scene[i][j + 1] == 32))
		{
			nb++;
			get_param(light, scene[i]);
		}
	}
	if (nb < 1)
	{
		ft_putstr_fd("The scene must contain one light\n", 2);
		ft_memory(0, 0);
	}
	return (EXIT_FAILURE);
    
}