/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:28:26 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/28 10:54:01 by jeepark          ###   ########.fr       */
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
# define SIZEX 1920
# define SIZEY 1080
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define MAT 11
# define SHINY 12
# define ESC 65307


/* Structures */

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
} t_vec3;

typedef struct s_cam
{
	t_vec3	position;
	t_vec3	direction;
	double		hfov;
	double		vfov;
} t_cam;

typedef struct s_light
{
	t_vec3	position;
	t_vec3	color;
	double	intensity;

} t_light;

typedef struct s_ambient_light
{
	t_vec3	color;
	double	intensity;
} t_ambient_light;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
	double	root;
} t_ray;

typedef struct s_object t_object;

typedef struct s_hit_point
{
	int		status;
	double	root;
	t_vec3  oc;
    double   a;
    double   b;
    double   c;
} t_hit_point;

typedef struct s_object
{
	int		type;
	t_vec3	center;
	t_vec3	color;
	t_vec3	direction;
	double	radius;
	double	height;
	t_hit_point		(*intersect) (t_ray *ray, t_object *obj);
	void	(*print_object) (t_object obj);
	int		surface;
	double	specular_exponent;
} t_object;

typedef struct s_view
{
	t_vec3	dot;
	t_vec3	color;
}			t_view;

typedef struct s_world 
{
	t_cam			cam;
	int				nb_light;
	t_light			**light;
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
	int		end;
} t_mlx;

/* Parsing */
int				check_filename(char *fd_name);
char			**get_scene(int fd, char *filename);
t_cam			get_camera(char **scene);
t_light			**get_light(t_world *world, char **scene);
t_ambient_light	get_ambient_light(char **scene);
void			create_sphere(char *data, t_object *sphere);
void			create_plane(char *data, t_object *plane);
void			create_cylinder(char *data, t_object *cylinder);
int				get_surface(char *line, int *idx);
double			get_specular_exponent(char *line, int *idx);


t_vec3			parse_position(char *line, int *idx);
t_vec3			parse_direction(char *line, int *idx);

t_object		**get_objects_list(char **scene);


/* MLX */
t_view			**init_view(t_world *world, t_view **view);
void			init_mlx(t_mlx *mlx);
void			put_pix(t_mlx *mlx, int x, int y, int color);

/* utils */
int				check_valid_color_range(t_vec3 color);
int				check_double(char *data);
void			jump_spaces(char *line, int *idx);
void 			jump_data(char*line, int *idx);
int				is_space(int c);
void    		print_world(t_view **view);
int				get_hex_color(t_vec3 rgb_color);
t_vec3			vec_substract(t_vec3 v1, t_vec3 v2);
t_vec3			vec_cross(t_vec3 v1, t_vec3 v2);
double			vec_dot(t_vec3 v1, t_vec3 v2);
t_vec3			vec_add(t_vec3 v1, t_vec3 v2);
t_vec3			vec_scalar(t_vec3 v1, double scalar);
t_vec3			vec_divide(t_vec3 v, double scalar);
double			vec_len(t_vec3 v);
t_vec3			vec_normal(t_vec3 v);

void			print_sp(t_object sp);

/* Mini Raytracing */
void    		draw_world(t_world *world, t_mlx *mlx);
int				hit_obj(t_ray *ray, t_world *world);
t_hit_point		hit_sp(t_ray *ray, t_object *sp);
double			compute_lighting(t_light *light, t_ray *ray, t_object *sp);
int				compute_color(t_ray *ray, t_object *object, t_world *world);

void			set_ray(t_ray *ray, t_cam cam, int i, int j);


#endif 