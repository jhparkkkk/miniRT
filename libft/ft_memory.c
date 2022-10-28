/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:57:55 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/28 17:14:27 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Malloc and put it in a garbage collector. Returns the ptr of the new
allocated element. if size == 0 and len == 0, free all the elements of the 
garbage collector with exit_success, if size == -1 and len == -1, exit with 
exit_success */
void	*ft_memory(int size, int len)
{
	static t_list	**bin = NULL;
	void			*content;

	if (!bin)
	{
		bin = ft_calloc(1, sizeof(t_list *));
		(*bin) = ft_lstnew(NULL);
	}
	content = NULL;
	content = ft_calloc(len, size);
	if (!content || (!size && !len) || (size == -1 && len == -1))
	{
		free(content);
		ft_lstclear(bin, &free);
		free(bin);
		if (!size && !len)
			exit (EXIT_SUCCESS);
		exit (EXIT_FAILURE);
	}
	else
		ft_lstadd_back(bin, ft_lstnew(content));
	return (content);
}
