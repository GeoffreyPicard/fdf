/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:27:17 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/06 15:17:37 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		list->content_size = 0;
		list->content = NULL;
		list->next = NULL;
	}
	else
	{
		if (!(list->content = (void*)malloc(sizeof(void) * content_size)))
			return (NULL);
		ft_memcpy((void*)(list->content), content, content_size);
		list->content_size = content_size;
	}
	return (list);
}
