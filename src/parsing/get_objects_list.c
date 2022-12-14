/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:35:03 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/28 17:04:25 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_object	*get_object(char *line)
{
	int			i;
	int			j;
	t_object	*new_object;

	i = 0;
	j = 0;
	new_object = NULL;
	new_object = ft_memory(sizeof(t_object), 1);
	if (is_space(line[j]))
		jump_spaces(line, &j);
	while (line[j + i] && !(line[j + i] == 32 || (line[j + i] >= 9
				&& line[j + i] <= 13)))
				i++;
	if (!ft_strncmp(line + j, "sp", 2) && !ft_strncmp(line + j, "sp", i))
		create_sphere(line + j + i, new_object);
	else if (!ft_strncmp(line + j, "pl", 2) && !ft_strncmp(line + j, "pl", i))
		create_plane(line + j + i, new_object);
	else if (!ft_strncmp(line + j, "cy", 2) && !ft_strncmp(line + j, "cy", i))
		create_cylinder(line + j + i, new_object);
	else
	{
		ft_putstr_fd("There is an unknown object in the map\n", 2);
		ft_memory(-1, -1);
	}
	return (new_object);
}

static int	count_objects(char **scene, t_world *world)
{
	int			i;
	int			j;
	int			nb;

	i = -1;
	nb = 0;
	while (scene[++i])
	{
		j = 0;
		jump_spaces(scene[i], &j);
		if (scene[i][j] && scene[i][j] != 'A' && scene[i][j] != 'C'
			&& scene[i][j] != 'L')
		{
			nb++;
			if (scene[i][j] == 'c')
				nb += 2;
		}
	}
	world->nb_obj = nb;
	return (nb);
}

t_object	**get_objects_list(char **scene, t_world *world)
{
	int			i;
	int			j;
	int			idx;
	t_object	**objects;

	i = -1;
	j = 0;
	idx = 0;
	objects = ft_memory(sizeof(t_object *), count_objects(scene, world) + 1);
	while (scene[++i])
	{
		j = 0;
		jump_spaces(scene[i], &j);
		if (scene[i][j] && scene[i][j] != 'A' && scene[i][j] != 'C'
			&& scene[i][j] != 'L')
		{
			objects[idx] = get_object(scene[i]);
			idx++;
			if (scene[i][j] == 'c')
				get_caps(objects, objects[idx - 1], &idx);
		}
	}
	objects[idx] = 0;
	return (objects);
}
