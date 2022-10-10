/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:05:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/10 13:54:40 by jeepark          ###   ########.fr       */
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

static void fill_mat_projection(double **mat, t_world *world)
{
    double scale = 1.0 / tan(degrees_to_radians(world->cam.hfov * 0.5f) * (M_PI / 180.0));
    double far = 100.0;
    double near = 0.1;
    double ratio = (double)SIZEX / (double)SIZEY;
    mat[0][0] = scale / ratio;
    mat[0][1] = 0.0;
    mat[0][2] = 0.0;
    mat[0][3] = 0.0;

    mat[1][0] = 0.0;
    mat[1][1] = scale;
    mat[1][2] = 0.0;
    mat[1][3] = 0.0;

    mat[2][0] = 0.0;
    mat[2][1] = 0.0;
    mat[2][2] = -(far + near) / (far - near);
    mat[2][3] = -2 * far * near / (far - near);

    mat[3][0] = 0.0;
    mat[3][1] = 0.0;
    mat[3][2] = -1.0;
    mat[3][3] = 0.0;

}


static void fill_mat_identity(double **mat)
{
    int i;

    i = 0;
    put_vec(mat[i], vec_init(1.0, 0.0, 0.0));
    mat[i][3] = 0.0;
    put_vec(mat[++i], vec_init(0.0, 1.0, 0.0));
    mat[i][3] = 0.0;
    put_vec(mat[++i], vec_init(0.0, 0.0, 1.0));
    mat[i][3] = 0.0;
    put_vec(mat[++i], vec_init(0.0, 0.0, 0.0));
    mat[i][3] = 1.0;
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

double  **mat_multiply(double **mat_1, double **mat_2, double **mat_res)
{
    int i;
    int j;
    int k;
    int sum;
    
    i = 0;
    while (mat_1[i] && i < 4)
    {
        j = 0;
        while (mat_2[j] && j < 4)
        {
            k = 0;
            sum = 0;
            while (k < 4)
            {
                sum += mat_1[i][k] * mat_2[k][j];
                k++;        
            }
            mat_res[i][j] = sum;
            j++;
        }
        i++;
    }
    return (mat_res);
}

void    print_matrix(double **mat)
{
    int i;
    int j;

    i = 0;
    while(i < 4)
    {
        j = 0;
        while(j < 4)
        {
            printf("%f  ", mat[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}




double  **init_view(t_world *world)
{
    t_vec3  forward;
    t_vec3  right;
    t_vec3  up;

    double  **mat_rotation;
    double  **mat_translation;
    double  **lookat;
    double  **identity;
    double  **projection;


    t_vec3  camera_direction;
    t_vec3  up;    
    
    forward = world->cam.direction;      // vec(0.0, 0.0, 0.0) ? openGL
    
    camera_direction = vec_normalize(vec_substract(forward, world->cam.position));

    up = vec_init(0.0, 1.0, 0.0);

    right = vec_normalize(vec_cross(up, camera_direction));
    
    up = vec_cross(camera_direction, right);
    
    mat_rotation = ft_memory(sizeof(double *), 4);
    int i = -1;
    while(++i < 4)
        mat_rotation[i] = ft_memory(sizeof(double), 4);
    
    fill_mat_rotation(mat_rotation, right, up, camera_direction);
    
    mat_translation = ft_memory(sizeof(double *), 4);
    i = -1;
    while(++i < 4)
        mat_translation[i] = ft_memory(sizeof(double), 4);
    
    fill_mat_translation(mat_translation, world->cam.position);
    
    lookat = ft_memory(sizeof(double *), 4);
    i = -1;
    while(++i < 4)
        lookat[i] = ft_memory(sizeof(double), 4);
    
    lookat = mat_multiply(mat_rotation, mat_translation, lookat);

    printf("\n--rotation matrix--\n");
    print_matrix(mat_rotation);
    printf("\n");

    printf("\n--translation matrix--\n");
    print_matrix(mat_translation);
    printf("\n");

    printf("\n--lookat matrix (cam to world)--\n");
    print_matrix(lookat);

    world->cam.right = camera_right;
    world->cam.up = up;
    world->cam.dir = camera_direction;
    
    t_vec3  w_prim;
    w_prim = vec_scalar(camera_right, (-SIZEX * 0.5));
    w_prim = vec_add(w_prim, vec_scalar(up, (-SIZEY * 0.5)));
    w_prim = vec_substract(w_prim, vec_scalar(camera_direction, ((SIZEY * 0.5) / tan(degrees_to_radians(world->cam.hfov * 0.5)))));
    
    world->cam.w_prim = w_prim; 

    identity = ft_memory(sizeof(double *), 4);
    i = -1;
    while(++i < 4)
        identity[i] = ft_memory(sizeof(double), 4);

    fill_mat_identity(identity);
    
    printf("\n--identity matrix--\n");
    print_matrix(identity);
    
    world->cam.mat_identity = identity;

    projection = ft_memory(sizeof(double *), 4);
    i = -1;
    while(++i < 4)
        projection[i] = ft_memory(sizeof(double), 4);
    
    fill_mat_projection(projection, world);

    printf("\n--projection matrix--\n");

    print_matrix(projection);

    world->cam.mat_projection = projection;
    
    return(lookat);
    
}