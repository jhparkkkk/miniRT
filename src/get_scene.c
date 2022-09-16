/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:56:29 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/16 15:31:52 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	count_lines(int fd)
{
	char	*line;
	int		size;

	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("Empty file\n", 2);
		exit(EXIT_FAILURE);
	}
	size = 0;
	while (line)
	{
		if (line[0] != '\n')
			size++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
	{
		perror("get_scene.c");
		exit(EXIT_FAILURE);
	}
	return (size);
}

static char	**get_scene_param(int fd, char **scene)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
		{
			scene[i] = ft_strdup(line);
			if (!scene[i])
			{
				ft_putstr_fd("Failed malloc\n", 2);
				//destroy avec free(line)
			}
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	scene[i] = NULL;
	free(line);
	return (scene);
}

char	**get_scene(int fd, char *filename)
{
	char	**scene;
	int		size;

	size = count_lines(fd);
	if (!size)
	{
		ft_putstr_fd("No instructions in file\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("get_scene.c");
		exit(EXIT_FAILURE);
	}
	scene = ft_memory(sizeof(char *), size + 1);
	if (!scene)
	{
		ft_putstr_fd("Failed malloc\n", 2);
		exit(EXIT_FAILURE);
	}
	scene = get_scene_param(fd, scene);
	return (scene);
}
