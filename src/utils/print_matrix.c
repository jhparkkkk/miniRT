/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:48:30 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/13 11:48:43 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/* debug printer */

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