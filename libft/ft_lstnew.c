/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:42:49 by cgosseli          #+#    #+#             */
/*   Updated: 2022/09/12 17:52:07 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_el;

	new_el = NULL;
	new_el = malloc(sizeof(t_list));
	if (!new_el)
		return (NULL);
	new_el->content = content;
	new_el->next = NULL;

	return (new_el);
}
