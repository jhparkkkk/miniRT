/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:28:26 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/10 15:12:34 by jeepark          ###   ########.fr       */
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
# define MAT 11
# define SHINY 12
# define ESC 65307
# define K_AMBIENT 0.1
# define K_DIFFUSE 0.5


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
	double	hfov;
	double	vfov;
	double	**lookat;
	double	**mat_identity;
	double	**mat_projection;
	// double	lookat[4][3];
	t_vec3	right;
	t_vec3	up;
	t_vec3	dir;
	t_vec3	w_prim;
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
	t_vec3		point;
	int			status;
	double		root;
	t_vec3  	oc;
    double	 	 a;
    double		 b;
    double		 c;
	t_vec3		normal;
	t_vec3		vec_light;
	t_vec3		reflect;
	t_vec3		view;
	double		n_dot_l;
	double		r_dot_v;
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

typedef struct s_viewport
{
	t_vec3	lower_left_corner;
	t_vec3	horizontal;
	t_vec3	vertical;
}			t_viewport;

typedef struct s_world 
{
	t_cam			cam;
	t_light			light;
	t_ambient_light ambient_light;
	t_object		**objects;
	int				nb_obj;
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
int				get_light(t_light *light, char **scene);
t_ambient_light	get_ambient_light(char **scene);
void			create_sphere(char *data, t_object *sphere);
void			create_plane(char *data, t_object *plane);
void			create_cylinder(char *data, t_object *cylinder);
int				get_surface(char *line, int *idx);
double			get_specular_exponent(char *line, int *idx);


t_vec3			parse_position(char *line, int *idx);
t_vec3			parse_direction(char *line, int *idx);

t_object 		**get_objects_list(char **scene, t_world *world);


/* MLX */
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
t_vec3			vec_init(double x, double y, double z);
t_vec3			vec_normalize(t_vec3 vec);
void			print_sp(t_object sp);
double			degrees_to_radians(double degrees);

/* Mini Raytracing */
void    		draw_world(t_world *world, t_mlx *mlx);
int				hit_obj(t_ray *ray, t_world *world);
t_hit_point		hit_sp(t_ray *ray, t_object *sp);
double			compute_lighting(t_ray *ray, t_object *sp, t_world *world);
int				compute_color(t_ray *ray, t_object *object, t_world *world);
t_ray			set_ray(t_cam cam, int x, int y, double lookat[4][4]);
t_viewport		get_viewport(t_cam cam);
void			mat_lookat(double mat[4][4], t_vec3 from, t_vec3 to);

/* debug printing */
void    print_matrix(double **mat);


#endif 