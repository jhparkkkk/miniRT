/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:36:45 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/21 14:44:46 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int get_hex_color(t_vec3 rgb_color)
{
    int hex_color;

    hex_color = 0 << 24; 
    hex_color += (int)rgb_color.x << 16;
    hex_color += (int)rgb_color.y << 8;
    hex_color += (int)rgb_color.z;
    return (hex_color);
}
