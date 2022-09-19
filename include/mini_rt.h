/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:28:26 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/19 17:17:16 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
 # define MINI_RT_H

/* Header files */

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/* Macros */

# define _USE_MATH_DEFINES 
# define WIDTH 10
# define HEIGHT 10
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
	float		hfov;
	float		vfov;
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
	t_vec3	center;
	t_vec3	color;
	t_vec3	direction;
	float	radius;
	float	height;
	t_vec3	(*intersect) (t_object object, t_ray ray);
} t_object;

typedef struct s_view
{
	t_vec3	dot;
	t_vec3	color;
}			t_view;

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

/* Parsing */
int				check_filename(char *fd_name);
char			**get_scene(int fd, char *filename);
t_cam			get_camera(char **scene);
int				get_light(t_light *light, char **scene);
t_ambient_light	get_ambient_light(char **scene);
void			create_sphere(char *data, t_object *sphere);
void			create_plane(char *data, t_object *plane);
void			create_cylinder(char *data, t_object *cylinder);


t_vec3			parse_position(char *line, int *idx);
t_vec3			parse_direction(char *line, int *idx);

t_object		**get_objects_list(char **scene);

t_view			**init_view(t_world *world, t_view **view);


/* utils */
int				check_valid_color_range(t_vec3 color);
int				check_float(char *data);
void			jump_spaces(char *line, int *idx);
void 			jump_data(char*line, int *idx);
int				is_space(int c);
void    		print_world(t_view **view);


#endif 