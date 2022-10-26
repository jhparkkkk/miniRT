/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:31:59 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/26 17:08:55 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"


int main(int ac, char **av)
{
	int		fd;
	char	**scene;
	t_world *world;
	t_mlx	mlx;
	
	world = ft_memory(sizeof(t_world), 1);
	if (ac != 2)
	{
		ft_putstr_fd("Too few argument\n", 2);
		ft_memory(0, 0);
	}
	fd = check_filename(av[1]);
	if (fd == EXIT_FAILURE)
		exit (EXIT_FAILURE);
	scene = get_scene(fd, av[1]);
	world->cam = get_camera(scene);
	get_light(&world->light, scene);
	world->amb_light = get_amb_light(scene);
	world->objects = get_objects_list(scene, world);
	
	init_mlx(&mlx);
	world->mlx = &mlx;
	
	// print_world(view);

	
	/* light */
	printf("\nlight position : %f, y : %f, z : %f\n", world->light.position.x, world->light.position.y, world->light.position.z);
	printf("light rgb x : %f, y : %f, z : %f\n", world->light.color.x, world->light.color.y, world->light.color.z);
	printf("light intens : %f\n", world->light.intens);
	
	/* camera */
	printf("\ncamera position x : %f, y : %f, z : %f\n", world->cam.position.x, world->cam.position.y, world->cam.position.z);
	printf("cam direction x : %f, y : %f, z : %f\n", world->cam.dir.x, world->cam.dir.y, world->cam.dir.z);
	printf("cam fov %f\n", world->cam.hfov);
	
	/* ambient light */
	printf("\nambient light color r : %f, g : %f, b: %f\n", world->amb_light.color.x, world->amb_light.color.y, world->amb_light.color.z);
	printf("ambient light intens %f\n", world->amb_light.intens);
	
	/* prirnting obj */
	int	i = 0;
	while (i < world->nb_obj)
	{
		world->objects[i]->print_object(*world->objects[i]);
		i++;
	}
	/* plane */
	// printf("\nplane center : %f, y : %f, z : %f\n", world->objects[1]->center.x, world->objects[1]->center.y, world->objects[1]->center.z);
	// printf("plane direction : %f, y : %f, z : %f\n", world->objects[1]->dir.x, world->objects[1]->dir.y, world->objects[1]->dir.z);
	// printf("plane color : %f, y : %f, z : %f\n", world->objects[1]->color.x, world->objects[1]->color.y, world->objects[1]->color.z);
	
	// /* cylinder */
	// printf("\ncylinder center : %f, y : %f, z : %f\n", world->objects[2]->center.x, world->objects[2]->center.y, world->objects[2]->center.z);
	// printf("cylinder direction : %f, y : %f, z : %f\n", world->objects[2]->dir.x, world->objects[2]->dir.y, world->objects[2]->dir.z);
	// printf("sphere radius %f\n", world->objects[2]->radius);
	// printf("sphere radius %f\n", world->objects[2]->height);
	// printf("plane color : %f, y : %f, z : %f\n", world->objects[2]->color.x, world->objects[2]->color.y, world->objects[2]->color.z);
	
	
	/* debug */
	// t_vec3 v1;
	// t_vec3 v2;
	// t_vec3 res;
	// v1.x = 3;
	// v1.y = 1;
	// v1.z = 4;
	
	// v2.x = 1;
	// v2.y = -2;
	// v2.z = 3;

	// res = vec_substract(v1, v2);
	
	// printf("\nx: %f\n", res.x);
	// printf("y: %f\n", res.y);
	// printf("z: %f\n", res.z);

	

	// int i = 0;
	// printf("\n");
	// while (scene[i])
	// {
	// 	printf("%s", scene[i]);
	// 	i++;
	// }
	// printf("\n");

	draw_world(world, &mlx);
	
	
	ft_memory(0, 0);
    return 0;
}

//segfault quand 0,,0 