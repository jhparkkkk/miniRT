/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:35:03 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/16 11:52:26 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "mini_rt.h"

static t_object	*get_object(char *line)
{
	int	i;
	int	j;
	t_object *new_object;

	i = 0;
	j = 0;
	new_object = NULL;
	new_object = ft_memory(sizeof(t_object), 1);
	jump_spaces(line, &j);
	while (line[j + i] && !(line[j + i] == 32 || (line[j + i] >= 9
			&& line[j + i] <= 13)))
		i++;
	printf("i : %i\n", i);
	if (!ft_strncmp(line + j, "sp", i))
		create_sphere(line + j + i, new_object);
	else if (!ft_strncmp(line + j, "pl", i))
		create_plane(line + j + i, new_object);
	else if (!ft_strncmp(line + j, "cy", i))
		create_cylinder(line + j + i, new_object);
	else
	{
		ft_putstr_fd("There is an unknown object in the map\n", 2);
		ft_memory(0, 0);
	}
	
	return (new_object);
}

static int	count_objects(char **scene)
{
	int			i;
	int			j;
	int			nb;

	i = -1;
	j = 0;
	nb = 0;
	while (scene[++i])
	{
		while (scene[i] && (scene[i][j] == 32 || (scene[i][j] >= 9
			&& scene[i][j] <= 13)))
			j++;
		if (scene[i][j] && scene[i][j] != 'A' && scene[i][j] != 'C'
			&& scene[i][j] != 'L')
			nb++;
	}
	return (nb);
}

t_object **get_objects_list(char **scene)
{
	int			i;
	int			j;
	int			idx;
	t_object	**objects;

	i = -1;
	j = 0;
	idx = 0;
	objects = NULL;

	objects = ft_memory(sizeof(t_object *), count_objects(scene));
	while (scene[++i])
	{
		jump_spaces(scene[i], &j);
		if (scene[i][j] && scene[i][j] != 'A' && scene[i][j] != 'C'
			&& scene[i][j] != 'L')
		{
			objects[idx] = get_object(scene[i]);
			// printf("get list : sphere radius %f\n", objects[0]->radius);
			
			idx++;
		}
	}	

    // int i;
    // int tab[3]
    // i = 0;
    // while(++i)
    //     tab[i] = i;
    // while(tab[i])
    //     printf("tab[i]");
	return (objects);
}