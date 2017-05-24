/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:39:26 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/13 10:33:12 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	if (!s)
		return (NULL);
	if (!(dst = ft_strnew(len)))
		return (NULL);
	while (j < len + start)
	{
		dst[i] = s[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
