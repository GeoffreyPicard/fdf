/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:46:11 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/04 09:18:11 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	if (little[0] == 0)
		return ((char*)big);
	while (big[k])
	{
		i = k;
		j = 0;
		while (big[i] == little[j])
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
