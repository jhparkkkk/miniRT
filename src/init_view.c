/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:05:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/04 11:06:51 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

typedef double mat4[16];

// static void init_dot(t_vec3 *dot, int i, int j)
// {
//     double   mid_SIZEY;

//     mid_SIZEY = SIZEY / 2;
//     dot->x = j - SIZEX/ 2;

//     dot->y = -i + mid_SIZEY;
//     // dot->y *= -1; 
     
//     dot->z = 0;   
// }

// t_view **init_view(t_world *world, t_view **view)
// {
//     (void)world;
//     int i;
//     int j;
    
//     view = ft_memory(sizeof(t_view *), SIZEY + 1);    
//     i = 0;
    
//     while (i < SIZEY + 1)
//     {
//         view[i] = malloc(sizeof(t_view) * (SIZEX +1));
//         j = 0;
//         while (j < SIZEX)
//         {
//             init_dot(&view[i][j].dot, i, j);

//             init_dot(&view[i][j].color,i, j);
//             j++;
//         }
//         i++;
//     }
//     return (view);
// }

void    put_vec(double *mat, t_vec3 vec)
{
    mat[0] = vec.x;
    mat[1] = vec.y;
    mat[2] = vec.z;
    mat[3] = 0.0;
}

static void put_last_row(double *mat)
{
    mat[0] = 0.0;
    mat[1] = 0.0;
    mat[2] = 0.0;
    mat[3] = 1.0;   
}


static void fill_mat_rotation(double **mat, t_vec3 right, t_vec3 up, t_vec3 direction)
{
    int i;

    i = 0;
    put_vec(mat[i], right);
    put_vec(mat[++i], up);
    put_vec(mat[++i], direction);
    put_last_row(mat[++i]);
}

static void fill_mat_translation(double **mat, t_vec3 camera_pos)
{
    int i;

    i = 0;
    put_vec(mat[i], vec_init(1.0, 0.0, 0.0));
    put_vec(mat[++i], vec_init(0.0, 1.0, 0.0));
    put_vec(mat[++i], vec_init(0.0, 0.0, 1.0));
    put_vec(mat[++i], vec_init(0.0, 0.0, 0.0));
    
    i = 0;
    mat[i][3] = -camera_pos.x;
    mat[++i][3] = -camera_pos.y;
    mat[++i][3] = -camera_pos.z;
    mat[++i][3] = 1.0;

}




void    init_view(t_world *world)
{
    t_vec3  camera_target;
    t_vec3  camera_right;
    t_vec3  camera_up;

    double  **mat_rotation;
    double  **mat_translation;
    


    t_vec3  camera_direction;
    t_vec3  up;    
    
    camera_target = vec_init(0.0,0.0,0.0);

    camera_direction = vec_normalize(vec_substract(world->cam.position, camera_target));

    up = vec_init(0.0, 1.0, 0.0);

    camera_right = vec_cross(up, camera_direction);
    
    camera_up = vec_cross(camera_direction, camera_right);
    
    mat_rotation = ft_memory(sizeof(double *), 4);
    int i = -1;
    while(++i < 4)
        mat_rotation[i] = ft_memory(sizeof(double), 4);
    
    fill_mat_rotation(mat_rotation, camera_right, camera_up, camera_direction);
    
    mat_translation = ft_memory(sizeof(double *), 4);
    i = -1;
    while(++i < 4)
        mat_translation[i] = ft_memory(sizeof(double), 4);
    
    fill_mat_translation(mat_translation, world->cam.position);
}