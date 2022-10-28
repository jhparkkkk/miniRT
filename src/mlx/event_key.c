/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:50:38 by jeepark           #+#    #+#             */
/*   Updated: 2022/10/27 18:51:34 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	press_key(int keycode, t_world *world)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(world->mlx->ptr, world->mlx->img);
	    mlx_destroy_window(world->mlx->ptr, world->mlx->win);
	    mlx_destroy_display(world->mlx->ptr);
	    free(world->mlx->ptr);
	    ft_memory(0, 0);
	    exit (0);
    }
	return (0);
}