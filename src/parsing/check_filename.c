/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:33:25 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/26 15:22:07 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/*  description : before opening file descriptor check if extension .rt
				  is correct
    proto       : int check_extension(char *fd_name)
*/

int	check_filename(char *fd_name)
{
	int	len;
	int	fd;

	if (!fd_name)
		return (EXIT_FAILURE);
	len = ft_strlen(fd_name);
	if (ft_strcmp(fd_name + len - 3, ".rt"))
	{
		ft_putstr_fd("Must end with \".rt\"\n", 2);
		return (EXIT_FAILURE);
	}
	fd = open(fd_name, O_RDONLY);
	if (fd == -1)
	{
		perror(fd_name);
		return (EXIT_FAILURE);
	}
	return (fd);
}
