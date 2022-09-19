/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:19:38 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/19 15:44:08 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void    print_world(t_view **view)
{
    int i;
    int j;

    i = 0;
    while(i <  WIDTH)
    {
        j = 0;
        while (j< HEIGHT)
        {
            printf("%.f;%.f ", view[i][j].dot.x, view[i][j].dot.y);
            j++;
        }
        printf("\n");
        i++;
    }
}