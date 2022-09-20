/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:09:27 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/20 16:14:29 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int len_clean_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
		i++;
	return (i);
}

float	ft_atof(const char *s)
{
	char			*tmp;
	int				i;
	long long int	dec;
	float			nb;

	i = 0;
	while (s[i] && s[i] != '.')
		i++;
	tmp = ft_substr(s, 0, i);
	dec = ft_atoi(tmp);
	if (s[i] == '.')
		i++;
	else
	{
		free(tmp);
		return ((float)dec);
	}
	free(tmp);
	tmp = ft_substr(s, i, 7);
	nb = (float)ft_atoi(tmp) / powf(10.0, (float)len_clean_space(tmp));
	free(tmp);
	if (s[0] == '-')
		nb = -nb;
	nb = nb + (float)dec;
	return (nb);
}