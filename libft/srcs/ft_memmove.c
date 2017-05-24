/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:32:17 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/04 11:35:26 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src <= dst)
		while (len > 0)
		{
			len--;
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
		}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
