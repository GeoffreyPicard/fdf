/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:04:12 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/06 12:40:57 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*str;

	i = 0;
	ch = (unsigned char)c;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == ch)
			return (&(str[i]));
		i++;
	}
	return (NULL);
}
