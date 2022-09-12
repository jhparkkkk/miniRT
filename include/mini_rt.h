/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:28:26 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/12 17:49:44 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
 # define MINI_RT_H

/* Header files */

#include "libft.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

/* Macros */
# define _USE_MATH_DEFINES 
# define WIDTH 1920
# define HEIGHT 1080
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define ESC 65307

/* Structures */

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
} t_vec3;

typedef struct s_cam
{
	t_vec3	position;
	t_vec3	direction;
	int		fov;
} t_cam;

typedef struct s_light
{
	t_vec3	position;
	t_vec3	color;
	float	intensity;
} t_light;

typedef struct s_ambient_light
{
	t_vec3	color;
	float	intensity;
} t_ambient_light;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
} t_ray;
typedef struct s_object t_object;

typedef struct s_object
{
	int		type;
	t_vec3	position;
	t_vec3	color;
	t_vec3	direction;
	float	radius;
	float	height;
	t_vec3	(*intersect) (t_object object, t_ray ray);
} t_object;

typedef struct s_world 
{
	t_cam			cam;
	t_light			light;
	t_ambient_light ambient_light;
	t_object		**objects;
} t_world;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
} t_mlx;


int	check_filename(char *fd_name);
char **get_scene(int fd, char *filename);
void	*ft_memory(int size, int len);

#endif 