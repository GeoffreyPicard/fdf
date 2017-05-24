/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:31:33 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/20 17:55:00 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst,
		const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size_dst;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (src[len])
		len++;
	while (dst[i] && i < size)
		i++;
	size_dst = i;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size_dst < size)
		dst[i] = '\0';
	return (size_dst + len);
}
