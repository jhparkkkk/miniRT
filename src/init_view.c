/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:05:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/19 16:23:34 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"



static void init_dot(t_vec3 *dot, int i, int j)
{
    float   mid_height;

    mid_height = HEIGHT / 2;
    dot->x = j - WIDTH/ 2;

    dot->y = -i + mid_height;
    // dot->y *= -1; 
     
    dot->z = 0;   
}

t_view **init_view(t_world *world, t_view **view)
{
    (void)world;
    int i;
    int j;
    
    view = ft_memory(sizeof(t_view *), HEIGHT + 1);    
    i = 0;
    
    while (i < HEIGHT + 1)
    {
        view[i] = malloc(sizeof(t_view) * (WIDTH +1));
        j = 0;
        while (j < WIDTH)
        {
            init_dot(&view[i][j].dot, i, j);

            init_dot(&view[i][j].color,i, j);
            j++;
        }
        i++;
    }
    return (view);
}