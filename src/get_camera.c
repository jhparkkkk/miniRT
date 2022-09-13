/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:16:19 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/13 18:34:13 by cgosseli         ###   ########.fr       */
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

static float	get_fov(char *line)
{
	float	ret;
	int		i;
	int		j;
	int		valid_nb;

	j = 0;
	valid_nb = 1;
	while (line[j] && (line[j] == 32 || (line[j] >= 9 && line[j] <= 13)))
		j++;
	i = 0;
	while (line[i + j] && !(line[i + j] == 32 || (line[i + j] >= 9
		&& line[i + j] <= 13)))
	{
		if ((!ft_isdigit(line[i + j]) && i != 0) || (!ft_isdigit(line[i + j])
			&& i == 0 && line[i + j] != '+' && line[i + j] != '-'))
			valid_nb = 0;
		i++;
	}
	ret = ft_atof(line + j);
	if (ret < 0 || ret > 180.0 || !valid_nb || empty_data(line + j))
	{
		ft_putstr_fd("Something is wrong with the field of view\n", 2);
		ft_memory(0, 0);
	}
	return (ret);
}

static t_cam get_camera_specs(char *line)
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

t_cam	get_camera(char **scene)
{
	int	i;
	int	j;
	int	nb;
	t_cam cam;

	
	i = 0;
	j = 0;
	nb = 0;
	while (scene[i])
	{
		while (scene[i] && (scene[i][j] == 32 || (scene[i][j] >= 9
			&& scene[i][j] <= 13)))
			j++;
		if (scene[i][j] && scene[i][j] == 'C')
		{
			nb++;
			cam = get_camera_specs(scene[i]);
		}
		i++;
	}	
	if (nb != 1)
	{
		ft_putstr_fd("The scene must contain one camera\n", 2);
		ft_memory(0, 0);
	}
	return (cam);
}

// t_cam	*get_camera(char **scene)
// {
// 	t_cam	*cam;

// 	cam = read_camera_specs(scene);
// 	if (!cam)
// 	{
// 		ft_putstr_fd("Something is wrong with the camera\nCam example :\
// C	-50,0,20	0,0,0	70", 2);
// 	}
// 	return (cam);
// }