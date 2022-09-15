/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:31:59 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/14 15:10:45 by jeepark          ###   ########.fr       */
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
	ambient_light = get_ambient_light(scene);
	
	/* light */
	printf("\nlight position : %f, y : %f, z : %f\n", light.position.x, light.position.y, light.position.z);
	printf("light rgb x : %f, y : %f, z : %f\n", light.color.x, light.color.y, light.color.z);
	printf("light intensity : %f\n", light.intensity);
	
	/* camera */
	printf("\ncamera position => x : %f, y : %f, z : %f\n", camera.position.x, camera.position.y, camera.position.z);
	printf("camera direction => x : %f, y : %f, z : %f\n", camera.direction.x, camera.direction.y, camera.direction.z);
	printf("camera fov => %f\n", camera.fov);
	
	/* ambient light */
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
