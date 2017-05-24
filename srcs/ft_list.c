/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:14:14 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/01 09:41:15 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_inttab	*ft_create_elem(int *tab)
{
	t_inttab	*list;

	if (!(list = (t_inttab*)malloc(sizeof(t_inttab))))
		return (NULL);
	list->tab = tab;
	list->next = NULL;
	return (list);
}

int			ft_list_size(t_inttab *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void		ft_list_push_back(t_inttab *list, int *tab)
{
	t_inttab	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem(tab);
}
