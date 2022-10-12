/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:05:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/12 17:30:17 by jeepark          ###   ########.fr       */
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

// void    put_vec(double *mat, t_vec3 vec)
// {
//     mat[0] = vec.x;
//     mat[1] = vec.y;
//     mat[2] = vec.z;
//     mat[3] = 0.0;
// }

// static void put_last_row(double *mat)
// {
//     mat[0] = 0.0;
//     mat[1] = 0.0;
//     mat[2] = 0.0;
//     mat[3] = 1.0;   
// }

// static void fill_mat_projection(double **mat, t_world *world)
// {
//     double scale = 1.0 / tan(degrees_to_radians(world->cam.hfov * 0.5f) * (M_PI / 180.0));
//     double far = 100.0;
//     double near = 0.1;
//     double ratio = (double)SIZEX / (double)SIZEY;
//     mat[0][0] = scale / ratio;
//     mat[0][1] = 0.0;
//     mat[0][2] = 0.0;
//     mat[0][3] = 0.0;

//     mat[1][0] = 0.0;
//     mat[1][1] = scale;
//     mat[1][2] = 0.0;
//     mat[1][3] = 0.0;

//     mat[2][0] = 0.0;
//     mat[2][1] = 0.0;
//     mat[2][2] = -(far + near) / (far - near);
//     mat[2][3] = -2 * far * near / (far - near);

//     mat[3][0] = 0.0;
//     mat[3][1] = 0.0;
//     mat[3][2] = -1.0;
//     mat[3][3] = 0.0;

// }


// static void fill_mat_identity(double **mat)
// {
//     int i;

//     i = 0;
//     put_vec(mat[i], vec_init(1.0, 0.0, 0.0));
//     mat[i][3] = 0.0;
//     put_vec(mat[++i], vec_init(0.0, 1.0, 0.0));
//     mat[i][3] = 0.0;
//     put_vec(mat[++i], vec_init(0.0, 0.0, 1.0));
//     mat[i][3] = 0.0;
//     put_vec(mat[++i], vec_init(0.0, 0.0, 0.0));
//     mat[i][3] = 1.0;
// }


// static void fill_mat_rotation(double **mat, t_vec3 right, t_vec3 up, t_vec3 direction)
// {
//     int i;

//     i = 0;
//     put_vec(mat[i], right);
//     put_vec(mat[++i], up);
//     put_vec(mat[++i], direction);
//     put_last_row(mat[++i]);
// }

// static void fill_mat_translation(double mat[4][4], t_vec3 camera_pos)
// {
//     int i;

//     i = 0;
//     put_vec(mat[i], vec_init(1.0, 0.0, 0.0));
//     put_vec(mat[++i], vec_init(0.0, 1.0, 0.0));
//     put_vec(mat[++i], vec_init(0.0, 0.0, 1.0));
//     put_vec(mat[++i], vec_init(0.0, 0.0, 0.0));
    
//     i = 0;
//     mat[i][3] = -camera_pos.x;
//     mat[++i][3] = -camera_pos.y;
//     mat[++i][3] = -camera_pos.z;
//     mat[++i][3] = 1.0;

// }

void mat_multiply(double mat_1[4][4], double mat_2[4][4], double mat_res[4][4])
{
    int i;
    int j;
    int k;
    int sum;
    
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
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
    // return (mat_res);
}

void    print_matrix(double mat[4][4])
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

void    inverse_matrix(double m[4][4], double r[4][4], t_vec3 from)
{
    r[0][0] = m[0][0];
    r[0][1] = m[1][0];
    r[0][2] = m[2][0];
    
    r[0][3] = from.x;
    // r[0][3] = 0.0f;
    r[1][0] = m[0][1];
    r[1][1] = m[1][1];
    r[1][2] = m[2][1];
    r[1][3] = from.y;

    // r[1][3] = 0.0f;
    r[2][0] = m[0][2];
    r[2][1] = m[1][2];
    r[2][2] = m[2][2];
    r[2][3] = from.z;
    // r[2][3] = 0.0f;
    r[3][0] = -(m[3][0] * r[0][0] + m[3][1] * r[1][0] + m[3][2] * r[2][0]);
    r[3][1] = -(m[3][0] * r[0][1] + m[3][1] * r[1][1] + m[3][2] * r[2][1]);
    r[3][2] = -(m[3][0] * r[0][2] + m[3][1] * r[1][2] + m[3][2] * r[2][2]);
    r[3][3] = 1.0f;
    m = r;
}

/* x_axis <=> right
   y_axis <=> up
   z_axis <=> forward */


/* tmp is a random vec to determine where right vector is pointing at */

void    mat_lookat(double mat[4][4], t_vec3 from, t_vec3 to)
{
    t_vec3  forward;
    t_vec3  right;
    t_vec3  up;
    t_vec3  tmp;
    
    forward = to;
    // forward = vec_normalize(vec_substract(to, from));  
    if (to.y != 0.0 && to.z == 0.0)
        tmp = vec_init(0.0, 0.0, 1.0);
    else
        tmp = vec_init(0.0, 1.0, 0.0);
    right = vec_cross(forward, tmp);
    up = vec_cross(right, forward);
    
    // right = vec_normalize(right);
    forward = vec_scalar(forward, -1.0);
    /* translation */ 
    // double mat_trans[4][4];

    // fill_mat_translation(mat_trans, from);

    
   
    /* rotation */
    // double mat[4][4];

    mat[0][0] = right.x,   mat[0][1] = right.y,   mat[0][2] = right.z,     mat[0][3] = vec_dot(right, from) * -1.0;
    mat[1][0] = up.x,      mat[1][1] = up.y,      mat[1][2] = up.z,        mat[1][3] = vec_dot(up, from)* -1.0;
    mat[2][0] = forward.x, mat[2][1] = forward.y, mat[2][2] = forward.z,   mat[2][3] = vec_dot(forward, from)* -1.0;
    mat[3][0] = 0.0,       mat[3][1] = 0.0,       mat[3][2] = 0.0,         mat[3][3] = 1.0;
    
    /* row major */
    // mat[0][0] = right.x,   mat[0][1] = right.y,   mat[0][2] = right.z,     mat[0][3] = 0.0;
    // mat[1][0] = up.x,      mat[1][1] = up.y,      mat[1][2] = up.z,        mat[1][3] = 0.0;
    // mat[2][0] = forward.x, mat[2][1] = forward.y, mat[2][2] = forward.z,   mat[2][3] = 0.0;
    // mat[3][0] = 0.0,       mat[3][1] = 0.0,       mat[3][2] = 0.0,         mat[3][3] = 1.0;


    /* maboye */

    // mat[0][0] = right.x;   mat[0][1] = up.x,   mat[0][2] = forward.x,   mat[0][3] = -vec_dot(right, from);
    // mat[1][0] = right.y,   mat[1][1] = up.y,   mat[1][2] = forward.y,   mat[1][3] = -vec_dot(up, from);
    // mat[2][0] = right.z,   mat[2][1] = up.z,   mat[2][2] = forward.z,   mat[2][3] = -vec_dot(forward, from);
    // mat[3][0] = from.x,    mat[3][1] = from.y, mat[3][2] = from.z,      mat[3][3] = 1.0;
   
    /* j'ai l'impression que reverse ne change rien */
    // double r[4][4];
    
    // inverse_matrix(mat, r, from);

    // print_matrix(mat);
    
    // mat_multiply(mat, mat_trans, mat_res);    
}