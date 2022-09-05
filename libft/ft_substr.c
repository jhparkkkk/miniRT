/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:31:25 by cgosseli          #+#    #+#             */
/*   Updated: 2021/12/02 16:20:24 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int					i;
	char				*s2;
	unsigned int		len_s;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len > (unsigned long)ft_strlen(s + start))
		len = ft_strlen(s + start);
	s2 = malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	if (start > len_s + 1)
	{
		s2[i] = '\0';
		return (s2);
	}
	while (len-- > 0 && s[start + i])
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
