/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:57:55 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/12 18:52:23 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*malloc and put it in a garbage collector. Returns the ptr of the new allocated
element. if size == 0 and len == 0, free all the elements of the garbage collector*/
void	*ft_memory(int size, int len)
{
	static t_list	**bin =  NULL;
	void			*content;
	t_list			*node = NULL;
	t_list			*tmp;

	if (!bin)
	{
		bin = malloc(sizeof(t_list *));
		(*bin) = ft_lstnew(NULL);
	}
	
	content = malloc(size * len);
	if (!content || (!size && !len))
	{
		node = (*bin);
		while (node->next)
		{
			free(node->content);
			tmp = node;
			free(tmp);
			node = node->next;		
		}
		free(bin);
	}
	else
	{
		node = ft_lstnew(content);
		node->head = (*bin);
	}
	ft_lstadd_back(bin, node);
	
	return (node->content);
	//free le gc if fsil malloc ou exit
}