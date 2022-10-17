/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:57:51 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/17 18:28:44 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	jump_data(char*line, int *idx)
{
	while (line[*idx] 
		&& !(line[*idx] == 32 || (line[*idx] >=9 && line[*idx] <= 13)))
		(*idx)++;	
}
