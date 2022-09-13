/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:31:59 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/13 16:34:19 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"


int main(int ac, char **av)
{
	int fd;
	char **scene;
	t_cam camera;

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
	printf("position => x : %f, y : %f, z : %f\n", camera.position.x, camera.position.y, camera.position.z);
	printf("direction  => x : %f, y : %f, z : %f\n", camera.direction.x, camera.direction.y, camera.direction.z);
	int i = 0;
	while (scene[i])
	{
		printf("%s", scene[i]);
		i++;
	}
	ft_memory(0, 0);
    return 0;
}
