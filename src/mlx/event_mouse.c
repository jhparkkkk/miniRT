/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:59:35 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/25 19:26:45 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	press_mouse(t_world *world)
{
    mlx_destroy_image(world->mlx->ptr, world->mlx->img);
	mlx_destroy_window(world->mlx->ptr, world->mlx->win);
	mlx_destroy_display(world->mlx->ptr);
	free(world->mlx->ptr);
	ft_memory(0, 0);
	exit (0);
}