/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:34:14 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/26 15:20:25 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	get_surface(char *line, int *idx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	jump_spaces(line, &j);
	i = j;
	while (line[i] && !(line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
		i++;
	(*idx) += i;
	if (i != j && !ft_strncmp(line + j, "shiny", i - j))
		return (SHINY);
	return (MAT);
}
