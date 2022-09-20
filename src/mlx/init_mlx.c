/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:59:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/20 11:59:19 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void    init_mlx(t_mlx *mlx)
{
    mlx->ptr = mlx_init();
	// if (!mlx->ptr)
	// {
    //     ft_memory(0, 0);
    //     exit (1);
    // }
	// mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "fdf");
	// if (!mlx->win)
	// {
    //     ft_memory(0, 0);
    //     exit (1);
    // }
	// mlx->img = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	// mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->len, &mlx->end);   
}