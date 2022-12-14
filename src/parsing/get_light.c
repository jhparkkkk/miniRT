/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:19:43 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/28 17:33:49 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	print_error(char *line)
{
	ft_putstr_fd(line, 2);
	ft_memory(-1, -1);
}

static t_light	*get_param(char *line)
{
	double	ret;
	int		i;
	t_light	*light;

	if (!check_elements_nb(4, line))
		print_error("The light doesn't have the right number of elements\n");
	i = 0;
	light = ft_memory(sizeof(t_light), 1);
	jump_spaces(line, &i);
	i++;
	light->position = parse_position(line + i, &i);
	jump_spaces(line, &i);
	ret = ft_atof(line + i);
	if (check_double(line + i) || ret < 0 || ret > 1.0)
		print_error("Something is wrong with the light intensity\n");
	light->intens = ret;
	jump_data(line, &i);
	light->color = parse_position(line + i, &i);
	if (check_valid_color_range(light->color))
		print_error("Something is wrong with the light color\n");
	return (light);
}

static int	count_lights(char **scene, t_world *world)
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
		if (scene[i][j] == 'L'
			&& ((scene[i][j + 1] >= 9 && scene[i][j + 1] <= 13)
			|| scene[i][j + 1] == 32))
			nb++;
	}
	world->nb_light = nb;
	return (nb);
}

/*	checks if light parameter exists and is valid in .rt file
	else prints error and exits
*/
t_light	**get_lights_list(char **scene, t_world *world)
{
	int			i;
	int			j;
	int			nb;
	t_light		**lights;

	nb = 0;
	i = -1;
	lights = ft_memory(sizeof(t_light *), count_lights(scene, world));
	while (scene[++i])
	{
		j = 0;
		jump_spaces(scene[i], &j);
		if (scene[i][j] == 'L'
			&& ((scene[i][j + 1] >= 9 && scene[i][j + 1] <= 13)
			|| scene[i][j + 1] == 32))
			lights[nb++] = get_param(scene[i]);
	}
	if (nb < 1)
	{
		ft_putstr_fd("The scene must contain at least one light\n", 2);
		ft_memory(-1, -1);
	}
	return (lights);
}
