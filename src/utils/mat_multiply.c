/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:08:35 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/14 18:08:59 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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