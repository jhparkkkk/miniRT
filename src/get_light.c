/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:19:43 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/14 11:43:17 by jeepark          ###   ########.fr       */
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
	i += 3;
	light->color = parse_position(line + i, &i);
	return 0;
}

/* check if there is another line beginning with the same letter 
*/
static int check_duplicate(char **scene, int i)
{
	int j;

	while(scene[i])
	{
		j = 0;
		while (scene[i][j] >= 9 && scene[i][j] <= 13)
		{
			if (scene[i][j] == 'L'
				&& scene[i][j] >= 9 && scene[i][j] <= 13)
				return (EXIT_FAILURE);
			j++;
		}
		i++;	
	}
	return (EXIT_SUCCESS);	
}



/*	checks if light parameter exists and is valid in .rt file
	else prints error and exits
*/

int get_line(t_light *light, char **scene, char key)
{
	(void)light;
	int i;
	int j;
	i = -1;
    while (scene[++i])
	{
		j = 0;
		while (scene[i][j] == 32 || (scene[i][j] >= 9 && scene[i][j] <= 13))
			j++;
		if (scene[i][j] == key
			&& scene[i][j + 1] >= 9 && scene[i][j + 1] <= 13)
		{
			printf("plop\n");
			if (!check_duplicate(scene, i + 1))
			{
				get_param(light, scene[i], j + 1);
				return (i);
			}
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_FAILURE);
    
}

/* init t_light structure from file .rt param */
void    get_light(t_light *light, char **scene)
{
	int		line;

    line = get_line(light, scene, 'L');
	if (line == -1)
		printf("doesn't exist");
}