/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:19:43 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/14 15:23:45 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"


static int	get_param(t_light *light, char *line, int i)
{
	
	light->position = parse_position(line + i, &i);
	printf("i : %i\n", i);
	while(line[i] == 32 || (line[i] >=9 && line[i] <= 13))
		i++;
	if (!check_float(line + i)) 
		light->intensity = ft_atof(line + i);
	// i += 3;
	while (line[i] && !(line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
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
		while (scene[i][j] == 32 || (scene[i][j] >= 9 && scene[i][j] <= 13))
			j++;
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