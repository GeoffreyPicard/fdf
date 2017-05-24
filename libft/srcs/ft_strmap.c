/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:09:29 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/05 15:21:44 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*dst;

	i = 0;
	if (!s)
		return (NULL);
	if (!(dst = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i])
	{
		dst[i] = f(s[i]);
		i++;
	}
	return (dst);
}
