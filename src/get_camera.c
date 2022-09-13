/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:16:19 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/13 15:01:40 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_cam *get_camera_specs(char *line)
{
	int		i;
	t_cam	*cam;

	cam = ft_memory(sizeof(t_cam), 1);
	i = 0;
	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	i++;
	cam->position = parse_position(line + i);
	printf("x : %f, y : %f, z : %f\n", cam->position.x, cam->position.y, cam->position.z);
	return (cam);
}

static t_cam	*read_camera_specs(char **scene)
{
	int	i;
	int	j;
	int	nb;
	t_cam *cam;

	
	i = 0;
	j = 0;
	nb = 0;
	while (scene[i])
	{
		while (scene[i][j] == 32 || (scene[i][j] >= 9 && scene[i][j] <= 13))
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

t_cam	*get_camera(char **scene)
{
	t_cam	*cam;

	cam = read_camera_specs(scene);
	if (!cam)
	{
		ft_putstr_fd("Something is wrong with the camera\nCam example :\
C	-50,0,20	0,0,0	70", 2);
	}
	return (cam);
}