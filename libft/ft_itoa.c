/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:59:30 by cgosseli          #+#    #+#             */
/*   Updated: 2022/06/12 18:57:33 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int				count;
	unsigned int	m;

	count = 1;
	if (n < 0)
	{
		m = -n;
		count++;
	}
	else
		m = n;
	while (m > 9)
	{
		m /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				len;
	unsigned int	m;

	len = ft_nbrlen(n);
	s = malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n < 0)
	{
		m = -n;
		s[0] = '-';
	}
	else
		m = n;
	while (m > 9)
	{
		s[--len] = (m % 10) + '0';
		m /= 10;
	}
	s[--len] = m + '0';
	return (s);
}
