/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:14:06 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/26 17:07:43 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static double	get_coordinates(char *data)
{
	double	ret;

	if (!data)
	{
		ft_putstr_fd("Something is wrong with the direction\n", 2);
		ft_memory(0, 0);
	}
	ret = ft_atof(data);
	if (check_double(data) || !(ret >= -1.0 && ret <= 1.0))
	{
		ft_putstr_fd("Something is wrong with the direction\n", 2);
		ft_memory(0, 0);
	}
	return (ret);
}

static t_vec3	extract_dir(char *data)
{
	t_vec3	dir;
	char	**coordinates;
	int		i;

	i = 0;
	coordinates = ft_split(data, ',');
	free(data);
	dir.x = get_coordinates(coordinates[0]);
	dir.y = get_coordinates(coordinates[1]);
	dir.z = get_coordinates(coordinates[2]);
	while (coordinates[i])
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
	return (dir);
}

/*
   Takes a line of the scene instructions beginning at the direction
   instruction. Checks if the direction contains 2 commas for x, y, z.
   Returns the vec3 direction or exit if something was wrong
*/
t_vec3	parse_dir(char *line, int *idx)
{
	int	i;
	int	j;
	int	nb_comma;

	j = 0;
	nb_comma = 0;
	jump_spaces(line, &j);
	i = j;
	while (line[i] && !(line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
	{
		if (line[i] == ',')
			nb_comma++;
		i++;
	}
	if (nb_comma != 2)
	{
		printf("LINE %s\n", line);
		ft_putstr_fd("Something is wrong with the direction\n", 2);
		ft_memory(0, 0);
	}
	(*idx) += i;
	return (extract_dir(ft_substr(line, j, i)));
}
