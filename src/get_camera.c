/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:16:19 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/14 11:31:10 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static float	get_fov(char *line)
{
	float	ret;
	int		j;

	j = 0;
	while (line[j] && (line[j] == 32 || (line[j] >= 9 && line[j] <= 13)))
		j++;
	ret = ft_atof(line + j);
	if (check_float(line + j) || ret < 0 || ret > 180.0)
	{
		ft_putstr_fd("Something is wrong with the field of view\n", 2);
		ft_memory(0, 0);
	}
	return (ret);
}

static t_cam	get_camera_specs(char *line)
{
	int		i;
	t_cam	cam;

	i = 0;
	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	i++;
	cam.position = parse_position(line + i, &i);
	cam.direction = parse_direction(line + i, &i);
	cam.fov = get_fov(line + i);
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
		while (scene[i] && (scene[i][j] == 32 || (scene[i][j] >= 9
			&& scene[i][j] <= 13)))
			j++;
		if (scene[i][j] && scene[i][j] == 'C')
		{
			nb++;
			cam = get_camera_specs(scene[i]);
		}
	}	
	if (nb != 1)
	{
		ft_putstr_fd("The scene must contain one camera\n", 2);
		ft_memory(0, 0);
	}
	return (cam);
}
