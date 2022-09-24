/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:59:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/24 14:45:51 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void    init_mlx(t_mlx *mlx)
{
    mlx->ptr = mlx_init();
	if (!mlx->ptr)
	{
        ft_memory(0, 0);
        exit (1);
    }
	mlx->win = mlx_new_window(mlx->ptr, SIZEX, SIZEY, "miniRT");
	if (!mlx->win)
	{
        ft_memory(0, 0);
        exit (1);
    }
	mlx->img = mlx_new_image(mlx->ptr, SIZEX, SIZEY);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->len, &mlx->end);   
    // mlx_hook(mlx.win, 2, 1L << 0, press_key, &map);
	// mlx_hook(mlx.win, 17, 1L << 17, press_mouse, &map);
	// mlx_loop(mlx->ptr);
    // mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}