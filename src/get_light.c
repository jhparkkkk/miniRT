/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:19:43 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/13 15:02:28 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"


// static int	get_param(t_light *light, char **scene, int i, int j)
// {
// 	while (scene[i][j])
// 	{
		
// 	}
// }

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

int get_line(t_light *light, char **scene, char *key)
{
	(void)light;
	int i;
	int j;
	i = -1;
	printf("key : %splop\n", key);
    while (scene[++i])
	{
		j = 0;
		while ((scene[i][j] >= 9 && scene[i][j] <= 13)
			|| scene[i][j] == 'L')
		{
			printf("scene : %s\n", &scene[i][j]);
			if (!ft_strncmp(&scene[i][j], key, 0)
				&& scene[i][j + 1] >= 9 && scene[i][j + 1] <= 13)
			{
				printf("found line\n");
				if (!check_duplicate(scene, i + 1)) // i + 1 pour commencer a regarder les doublons des la ligne suivante	
				{
					printf("no duplicate\n");
					// get_param(light, scene, i, j + 1);
					return (i);
				}
				return (EXIT_FAILURE);
			}
			j++; 
		}
	}
	return (EXIT_FAILURE);
    
}

/* init t_light structure from file .rt param */
void    get_light(char **scene)
{
    t_light light;
	int		line;

    line = get_line(&light, scene, "L");
	if (line == -1)
		printf("doesn't exist");
}