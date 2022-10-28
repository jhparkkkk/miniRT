/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:28:26 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/28 14:56:00 by cgosseli         ###   ########.fr       */
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
# define SIZEX 1920.0
# define SIZEY 1080.0
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3
# define CIRC_PLANE 4
# define MAT 11
# define SHINY 12
# define ESC 65307
# define K_AMBIENT 0.4
# define K_DIFFUSE 20.0

/* Structures */

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_cam
{
	t_vec3	position;
	t_vec3	dir;
	double	hfov;
	double	**lookat;
	double	**mat_identity;
	double	**mat_projection;
	t_vec3	right;
	t_vec3	up;
}	t_cam;

typedef struct s_light
{
	t_vec3	position;
	t_vec3	color;
	double	intens;
}	t_light;

typedef struct s_amb_light
{
	t_vec3	color;
	double	intens;
}	t_amb_light;

typedef struct s_object	t_object;

typedef struct s_hit_point
{
	t_vec3		point;
	int			status;
	double		root;
	t_vec3		oc;
	double		a;
	double		b;
	double		c;
	t_vec3		normal;
	t_vec3		vec_light;
	t_vec3		reflect;
	t_vec3		view;
	double		ndotl;
	double		rdotv;
}	t_hit_point;

typedef struct s_ray
{
	t_vec3		origin;
	t_vec3		dir;
	t_hit_point	hit;
}	t_ray;

typedef struct s_object
{
	int				type;
	t_vec3			center;
	t_vec3			color;
	t_vec3			dir;
	double			radius;
	double			height;
	void			(*intersect)(t_ray *, t_object *, double, t_hit_point *);
	void			(*print_object)(t_object obj);
	int				surface;
	double			specular_exponent;
	double			k_spec;
}	t_object;

typedef struct s_view
{
	t_vec3	dot;
	t_vec3	color;
}	t_view;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		end;
}	t_mlx;

typedef struct s_world
{
	t_cam			cam;
	t_light			**lights;
	t_amb_light		amb_light;
	t_object		**objects;
	int				nb_obj;
	int				nb_light;
	t_mlx			*mlx;
}	t_world;

/* Parsing */
int				check_filename(char *fd_name);
char			**get_scene(int fd, char *filename);
t_light			**get_lights_list(char **scene, t_world *world);
t_cam			get_camera(char **scene);
t_amb_light		get_amb_light(char **scene);
void			create_sphere(char *data, t_object *sphere);
void			create_plane(char *data, t_object *plane);
void			create_cylinder(char *data, t_object *cylinder);
void			get_caps(t_object **objects, t_object *cy, int *idx);
int				get_surface(char *line, int *idx);
double			get_specular_exponent(char *line, int *idx);
int				check_elements_nb(int expected, char *data);

t_vec3			parse_position(char *line, int *idx);
t_vec3			parse_dir(char *line, int *idx);

t_object		**get_objects_list(char **scene, t_world *world);

/* MLX */
void			init_mlx(t_mlx *mlx);
void			put_pix(t_mlx *mlx, int x, int y, int color);
int				press_key(int keycode, t_world *world);
int				press_mouse(t_world *world);

/* utils */
int				check_valid_color_range(t_vec3 color);
int				check_double(char *data);
void			jump_spaces(char *line, int *idx);
void			jump_data(char*line, int *idx);
int				is_space(int c);
void			print_world(t_view **view);
int				get_hex_color(t_vec3 rgb_color);
t_vec3			vec_substract(t_vec3 v1, t_vec3 v2);
t_vec3			vec_cross(t_vec3 v1, t_vec3 v2);
double			vec_dot(t_vec3 v1, t_vec3 v2);
t_vec3			vec_add(t_vec3 v1, t_vec3 v2);
t_vec3			vec_scalar(t_vec3 v1, double scalar);
t_vec3			vec_divide(t_vec3 v, double scalar);
double			vec_len(t_vec3 v);
t_vec3			vec_init(double x, double y, double z);
t_vec3			vec_normalize(t_vec3 vec);
int				vec_compare(t_vec3 v1, t_vec3 v2);
t_vec3			mat_multiply_vec(double mat[4][4], t_vec3 vec);

void			print_sp(t_object sp);
void			print_pl(t_object pl);
void			print_cap(t_object cap);
void			print_cy(t_object cy);
double			degrees_to_radians(double degrees);

/* Mini Raytracing */
void			draw_world(t_world *world, t_mlx *mlx);
double			compute_lighting(t_ray *ray, t_object *sp,
					t_world *world, t_light light);
int				compute_color(t_ray *ray, t_object *object, t_world *world);
t_ray			set_ray(t_cam cam, int x, int y, double lookat[4][4]);
void			mat_lookat(double mat[4][4], t_vec3 from, t_vec3 to);

/* ===== Intersection ===== */

int				hit_obj(t_ray *ray, t_world *world, int shadow);
void			hit_sp(t_ray *ray, t_object *sp,
					double shadow, t_hit_point *hit);
void			hit_pl(t_ray *ray, t_object *pl,
					double shadow, t_hit_point *hit);
void			hit_cy(t_ray *ray, t_object *cy,
					double shadow, t_hit_point *hit);
void			hit_cap(t_ray *ray, t_object *cap,
					double shadow, t_hit_point *hit);

/* debug printing */
void			print_matrix(double mat[4][4]);

/* ===== Shadows ===== */
int				shadow(t_vec3 point, t_vec3 vec_light,
					t_world *world, t_light light);

#endif 