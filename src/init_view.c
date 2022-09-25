/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:05:49 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/25 16:40:03 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"



static void init_dot(t_vec3 *dot, int i, int j)
{
    double   mid_SIZEY;

    mid_SIZEY = SIZEY / 2;
    dot->x = j - SIZEX/ 2;

    dot->y = -i + mid_SIZEY;
    // dot->y *= -1; 
     
    dot->z = 0;   
}

t_view **init_view(t_world *world, t_view **view)
{
    (void)world;
    int i;
    int j;
    
    view = ft_memory(sizeof(t_view *), SIZEY + 1);    
    i = 0;
    
    while (i < SIZEY + 1)
    {
        view[i] = malloc(sizeof(t_view) * (SIZEX +1));
        j = 0;
        while (j < SIZEX)
        {
            init_dot(&view[i][j].dot, i, j);

            init_dot(&view[i][j].color,i, j);
            j++;
        }
        i++;
    }
    return (view);
}