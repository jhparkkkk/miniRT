/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:16:19 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/28 16:33:09 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static double	get_hfov(char *line)
{
	double	ret;
	int		j;

	j = 0;
	jump_spaces(line, &j);
	ret = ft_atof(line + j);
	if (ret == 180.0)
		ret = 179.8;
	if (check_double(line + j) || ret < 0.0 || ret > 180.0)
	{
		ft_putstr_fd("Something is wrong with the field of view\n", 2);
		ft_memory(-1, -1);
	}
	return (ret);
}

static t_cam	get_camera_specs(char *line)
{
	int		i;
	t_cam	cam;

	if (!check_elements_nb(4, line))
	{
		ft_putstr_fd("Camera: invalid number of elements\n", 2);
		ft_memory(-1, -1);
	}
	i = 0;
	jump_spaces(line, &i);
	i++;
	cam.position = parse_position(line + i, &i);
	cam.dir = vec_normalize(parse_dir(line + i, &i));
	cam.hfov = get_hfov(line + i);
	return (cam);
}

/*Goes through the **scene and checks if there is one and only camera.
Parse the line of the camera to get its specs. Returns the camera and its
specs, exit if the camera was not valid*/
t_cam	get_camera(char **scene)
{
	int		i;
	int		j;
	int		nb;
	t_cam	cam;

	i = -1;
	j = 0;
	nb = 0;
	while (scene[++i])
	{
		jump_spaces(scene[i], &j);
		if (scene[i][j] && scene[i][j] == 'C'
			&& ((scene[i][j + 1] >= 9 && scene[i][j + 1] <= 13)
			|| scene[i][j + 1] == 32))
		{
			nb++;
			cam = get_camera_specs(scene[i]);
		}
	}	
	if (nb != 1)
	{
		ft_putstr_fd("The scene must contain one camera\n", 2);
		ft_memory(-1, -1);
	}
	return (cam);
}
