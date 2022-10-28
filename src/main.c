/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:31:59 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/28 15:04:44 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(int ac, char **av)
{
	int		fd;
	char	**scene;
	t_world	*world;
	t_mlx	mlx;

	world = ft_memory(sizeof(t_world), 1);
	if (ac != 2)
	{
		ft_putstr_fd("Too few argument\n", 2);
		ft_memory(-1, -1);
	}
	fd = check_filename(av[1]);
	if (fd == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	scene = get_scene(fd, av[1]);
	world->cam = get_camera(scene);
	world->lights = get_lights_list(scene, world);
	world->amb_light = get_amb_light(scene);
	world->objects = get_objects_list(scene, world);
	init_mlx(&mlx);
	world->mlx = &mlx;
	draw_world(world, &mlx);
	ft_memory(0, 0);
	return (0);
}
