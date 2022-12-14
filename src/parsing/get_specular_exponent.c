/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specular_exponent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:33:16 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/27 18:45:15 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	get_specular_exponent(char *line, int *idx)
{
	double	ret;
	int		j;

	j = 0;
	jump_spaces(line, &j);
	ret = ft_atof(line + j);
	if (check_double(line + j) || ret <= 0.0 || ret > 1001.0)
	{
		ft_putstr_fd("Something is wrong with the specular exponent\n", 2);
		ft_memory(-1, -1);
	}
	while (line[j] && !(line[j] == 32 || (line[j] >= 9 && line[j] <= 13)))
		j++;
	(*idx) += j;
	return (ret);
}
