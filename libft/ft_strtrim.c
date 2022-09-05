/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:18:40 by cgosseli          #+#    #+#             */
/*   Updated: 2021/12/02 12:59:50 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	char	*s2;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (i < len && ft_strchr(set, s1[i]))
		i++;
	while (i < len && ft_strchr(set, s1[len]))
		len--;
	if (len == 0)
		s2 = ft_substr(s1, 0, 0);
	else
		s2 = ft_substr(s1, i, len - i + 1);
	if (!s2)
		return (NULL);
	return (s2);
}
