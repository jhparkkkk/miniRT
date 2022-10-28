/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:59:39 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/28 15:02:09 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
	{
		ft_memory(-1, -1);
		exit (1);
	}
	mlx->win = mlx_new_window(mlx->ptr, SIZEX, SIZEY, "miniRT");
	if (!mlx->win)
	{
		ft_memory(-1, -1);
		exit (1);
	}
	mlx->img = mlx_new_image(mlx->ptr, SIZEX, SIZEY);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->len, &mlx->end);
}
