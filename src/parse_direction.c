/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:14:06 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/13 16:09:17 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	empty_data(char *data)
{
	int	i;
	int	empty_line;

	i = 0;
	empty_line = 1;
	while (data[i])
	{
		if (data[i] == 32 || (data[i] >= 9 && data[i] <= 13))
			break ;
		empty_line = 0;
		i++;
	}
	if ((i == 1 && (data[0] == '-' || data[0] == '+')) || empty_line)
		return (1);
	return (0);
}

static float	get_coordinates(char *data)
{
	int	i;
	int	nb_dot;
	int	valid_coordinates;
	float	ret;

	i = 0;
	nb_dot = 0;
	valid_coordinates = 1;
	while(data[i] && !(data[i] == 32 || (data[i] >= 9 && data[i] <= 13)))
	{
		if (data[i] == '.')
			nb_dot++;
		if ((!ft_isdigit(data[i]) && i != 0) || (!ft_isdigit(data[i]) && i == 0
			&& data[i] != '+' && data[i] != '-'))
			valid_coordinates = 0;
		i++;
	}
	ret = ft_atof(data);
	if (nb_dot > 1 || !valid_coordinates || empty_data(data)
		|| !(ret >= -1.0 && ret <= 1.0))
	{
		ft_putstr_fd("Something is wrong with the direction\n", 2);
		ft_memory(0, 0);
	}
	return (ft_atof(data));
}

static t_vec3	extract_direction(char *data)
{
	t_vec3 direction;
	char **coordinates;
	int	i;

	i = 0;
	coordinates = ft_split(data, ',');
	free(data);
	direction.x = get_coordinates(coordinates[0]);
	direction.y = get_coordinates(coordinates[1]);
	direction.z = get_coordinates(coordinates[2]);
	while (coordinates[i])
	{
		free(coordinates[i]);
		i++;
	}
	free(coordinates);
	return (direction);
}

/* Takes a line of the scene instructions beginning at the direction instruction.
Checks if the direction contains 2 commas for x, y, z. Returns the vec3 direction
or exit if something was wrong*/
t_vec3	parse_direction(char *line)
{
	int	i;
	int	j;
	int	nb_comma;
	
	i = 0;
	j = 0;
	nb_comma = 0;
	while (line[j] && (line[j] == 32 || (line[j] >= 9 && line[j] <= 13)))
		j++;
	i = j;
	while (line[i] && !(line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
	{
		if (line[i] == ',')
			nb_comma++;
		i++;
	}
	if (nb_comma != 2)
	{
		ft_putstr_fd("Something is wrong with the direction\n", 2);
		ft_memory(0, 0);
	}
	return (extract_direction(ft_substr(line, j, i)));
}