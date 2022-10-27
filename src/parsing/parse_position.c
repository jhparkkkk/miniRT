/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:57:20 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/27 18:45:15 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static double	get_coordinates(char *data)
{
	if (!data || check_double(data))
	{
		ft_putstr_fd("Something is wrong with coordinates\n", 2);
		ft_memory(-1, -1);
	}
	return (ft_atof(data));
}

/*Returns the vec3 from the data string*/
static t_vec3	extract_position(char *data)
{
	t_vec3	position;
	char	**coordinates;
	int		i;

	i = 0;
	coordinates = ft_split(data, ',');
	free(data);
	position.x = get_coordinates(coordinates[0]);
	position.y = get_coordinates(coordinates[1]);
	position.z = get_coordinates(coordinates[2]);
	while (coordinates[i])
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
	return (position);
}

/* Takes a line of the scene instructions beginning at the position instruction.
Checks if the position contains 2 commas for x, y, z. Returns the vec3 position
or exit if something was wrong*/
t_vec3	parse_position(char *line, int *idx)
{
	int	i;
	int	j;
	int	nb_comma;

	i = 0;
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
		ft_putstr_fd("Something is wrong with coordinates\n", 2);
		ft_memory(-1, -1);
	}
	(*idx) += i;
	return (extract_position(ft_substr(line, j, i)));
}
