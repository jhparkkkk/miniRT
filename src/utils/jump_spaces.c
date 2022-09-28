/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:55:17 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/28 11:05:40 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	jump_spaces(char *line, int *idx)
{
	// if (!is_space(line[*idx]))
	// 	return;
	while(line[*idx] 
		&& (line[*idx] == 32 || (line[*idx] >=9 && line[*idx] <= 13)))
		(*idx)++;	
}
