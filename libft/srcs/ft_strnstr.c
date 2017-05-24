/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:47:13 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/04 09:16:45 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (little[0] == 0)
		return ((char*)big);
	while (big[k] && i < len)
	{
		i = k;
		j = 0;
		while (big[i] == little[j] && i < len)
		{
			if (little[j + 1] == '\0')
				return (char *)(big + i - j);
			i++;
			j++;
		}
		k++;
	}
	return (NULL);
}
