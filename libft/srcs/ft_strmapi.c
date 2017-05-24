/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:27:28 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/04 14:33:25 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(dst = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	return (dst);
}
