/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 23:05:03 by jeepark           #+#    #+#             */
/*   Updated: 2022/09/12 10:47:20 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_nchr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

static char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_s;

	i = 0;
	j = 0;
	if (ft_nchr(s2) == 0)
		new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	else
		new_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_nchr(s2) + 1));
	if (!new_s)
		return (NULL);
	while (s1 && s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		new_s[i++] = s2[j++];
	if (s2[j] == '\n')
		new_s[i++] = '\n';
	new_s[i] = '\0';
	return (new_s);
}

static void	ft_get_buffer(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = ft_nchr(buffer);
	if (j == 0)
	{
		buffer[0] = '\0';
		return ;
	}
	while (buffer[j])
	{
		buffer[i] = buffer[j];
		i++;
		j++;
	}
	buffer[i] = '\0';
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*s;
	char		*dent;
	int			ret;

	if (read(fd, buffer, 0) == -1)
		return (NULL);
	s = NULL;
	if (buffer[0])
		s = ft_gnl_strjoin(s, buffer);
	while (!ft_nchr(buffer))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == 0)
		{
			ft_get_buffer(buffer);
			return (s);
		}
		buffer[ret] = '\0';
		dent = s;
		s = ft_gnl_strjoin(s, buffer);
		free(dent);
	}
	ft_get_buffer(buffer);
	return (s);
}
