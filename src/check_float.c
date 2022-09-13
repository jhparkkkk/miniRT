/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:46:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/13 19:04:29 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	empty_data(char *data)
{
	int	i;
	int	empty_line;

	i = 0;
	empty_line = 1;
	while (data[i])
	{
		if (data[i] == 32 || (data[i] >= 9 && data[i] <= 13))
			break ;
		empty_line = 0;
		i++;
	}
	if ((i == 1 && (data[0] == '-' || data[0] == '+')) || empty_line)
		return (1);
	return (0);
}

/*Checks if the str can be converted to a float : only digits, only one
dot, not an empty or only emptry spaces string. Returns 1 on failure, 
0 on success*/
int	check_float(char *data)
{
	int	i;
	int	nb_dot;
	int	valid_float;

	i = 0;
	nb_dot = 0;
	valid_float = 1;
	while(data[i] && !(data[i] == 32 || (data[i] >= 9 && data[i] <= 13)))
	{
		if (data[i] == '.')
			nb_dot++;
		if (((!ft_isdigit(data[i]) && i != 0) || (!ft_isdigit(data[i]) && i == 0
			&& data[i] != '+' && data[i] != '-')) && data[i] != '.')
			valid_float = 0;
		i++;
	}
	if (nb_dot > 1 || !valid_float || empty_data(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}