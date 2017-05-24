/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:13:04 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/01 09:53:37 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_count_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			*ft_strdup_int(int *src, int len)
{
	int i;
	int *dst;

	i = 0;
	if (!(dst = (int *)malloc(sizeof(int) * len)))
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int			**ft_list_to_tab(t_inttab *list, int h, int l)
{
	int **tab;
	int i;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * h)))
		return (NULL);
	while (i < h)
	{
		tab[i] = ft_strdup_int(list->tab, l);
		list = list->next;
		i++;
	}
	return (tab);
}

t_inttab	*ft_parse(int fd, char **line, int *l)
{
	int			*inttab;
	t_inttab	*list;
	char		**tab;

	get_next_line(fd, line);
	if (*line == NULL)
		return (NULL);
	tab = ft_char_to_tab(*line);
	*l = ft_count_len(tab);
	inttab = ft_tab_to_inttab(tab);
	list = ft_create_elem(inttab);
	ft_strdel(tab);
	while (get_next_line(fd, line) == 1)
	{
		tab = ft_char_to_tab(*line);
		inttab = ft_tab_to_inttab(tab);
		ft_list_push_back(list, inttab);
	}
	return (list);
}

int			*ft_tab_to_inttab(char **tab)
{
	int			i;
	int			j;
	int			*dst;

	i = 0;
	j = 0;
	while (tab[i])
		i++;
	if (!(dst = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		dst[j] = ft_atoi(tab[i]);
		i++;
		j++;
	}
	return (dst);
}
