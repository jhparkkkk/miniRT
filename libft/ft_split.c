/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:19:09 by cgosseli          #+#    #+#             */
/*   Updated: 2021/12/02 18:21:13 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		while (s[i] && !(s[i] == c))
		{
			count++;
			while (s[i] && !(s[i] == c))
				i++;
		}
	}
	return (count);
}

static char	*ft_sdupword(const char *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && !(s[i] == c))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && !(s[i] == c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**dest;

	i = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!dest)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && !(*s == c))
		{
			dest[i++] = ft_sdupword(s, c);
			while (*s && !(*s == c))
				s++;
		}
	}
	dest[i] = 0;
	return (dest);
}
