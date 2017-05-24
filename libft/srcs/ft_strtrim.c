/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:58:39 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/05 15:44:16 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*dst;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (i == ft_strlen(s))
	{
		if (!(dst = ft_strnew(ft_strlen(s))))
			return (NULL);
	}
	else
	{
		if (!(dst = ft_strsub(s, i, (j - i + 1))))
			return (NULL);
	}
	return (dst);
}
