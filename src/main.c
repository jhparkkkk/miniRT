/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:31:59 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/14 11:16:53 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"


int main(int ac, char **av)
{
	int fd;
	char **scene;
	t_cam camera;
	t_light light;

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
	printf("x : %f, y : %f, z : %f\n", camera.position.x, camera.position.y, camera.position.z);
	get_light(&light, scene);
	printf("get_light x : %f, y : %f, z : %f\n", light.position.x, light.position.y, light.position.z);

	printf("position => x : %f, y : %f, z : %f\n", camera.position.x, camera.position.y, camera.position.z);
	printf("direction => x : %f, y : %f, z : %f\n", camera.direction.x, camera.direction.y, camera.direction.z);
	printf("fov => %f\n", camera.fov);
	int i = 0;
	while (scene[i])
	{
		printf("%s", scene[i]);
		i++;
	}
	ft_memory(0, 0);
    return 0;
}
