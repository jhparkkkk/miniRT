/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:57:55 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/19 15:27:26 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*malloc and put it in a garbage collector. Returns the ptr of the new allocated
element. if size == 0 and len == 0, free all the elements of the garbage collector*/
void	*ft_memory(int size, int len)
{
	static t_list	**bin =  NULL;
	void			*content;
	
	if (!bin)
	{
		bin = ft_calloc(1, sizeof(t_list *));
		// ft_bzero(bin, sizeof(t_list *));
		//bin = malloc(sizeof(t_list *));
		(*bin) = ft_lstnew(NULL);
	}
	content = NULL;
	content = ft_calloc(len, size);
	if (!content || (!size && !len))
	{
		free(content);
		ft_lstclear(bin, &free);
		free(bin);
		exit (EXIT_FAILURE);
	}
	else
		ft_lstadd_back(bin, ft_lstnew(content));
	return (content);
}