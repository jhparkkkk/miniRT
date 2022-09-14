/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:31:59 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/14 13:33:51 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"


int main(int ac, char **av)
{
	int fd;
	char **scene;
	t_cam camera;
	t_light light;
	t_ambient_light ambient_light;

	if (ac != 2)
	{
		printf("Too few argument\n");
		exit (EXIT_FAILURE);
	}
	fd = check_filename(av[1]);
	if (fd == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	scene = get_scene(fd, av[1]);
	camera = get_camera(scene);
	get_light(&light, scene);
	printf("get_light x : %f, y : %f, z : %f\n", light.position.x, light.position.y, light.position.z);
	ambient_light = get_ambient_light(scene);
	printf("ambient light color => r : %f, g : %f, b: %f\nintensity : %f\n", ambient_light.color.x, ambient_light.color.y, ambient_light.color.z, ambient_light.intensity);
	
	int i = 0;
	while (scene[i])
	{
		printf("%s", scene[i]);
		i++;
	}
	ft_memory(0, 0);
    return 0;
}
