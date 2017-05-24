/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:18:52 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/13 10:34:30 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dst;
	size_t	i;

	i = 0;
	if (!(dst = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(dst, size);
	return (dst);
}
