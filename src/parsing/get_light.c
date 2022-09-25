/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:19:43 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/25 16:40:03 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"


static int	get_param(t_light *light, char *line, int i)
{
	if (is_space(line[0]))
	{
		jump_spaces(line, &i);
		jump_data(line, &i);
	}
	light->position = parse_position(line + i, &i);
	jump_spaces(line, &i);
	if (!check_double(line + i)) 
		light->intensity = ft_atof(line + i);
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
			&& scene[i][j + 1] >= 9 && scene[i][j + 1] <= 13)
		{
			nb++;
			get_param(light, scene[i], i);
		}
	}
	if (nb != 1)
	{
		ft_putstr_fd("The scene must contain one light\n", 2);
		ft_memory(0, 0);
	}
	return (EXIT_FAILURE);
    
}