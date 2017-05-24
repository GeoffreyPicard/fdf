/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:51:18 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/04 16:32:36 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	i = 0;
	while (s1[i])
		i++;
	if ((cpy = (char *)malloc(sizeof(char) * (i + 1))))
	{
		i = 0;
		while (s1[i])
		{
			cpy[i] = s1[i];
			i++;
		}
		cpy[i] = '\0';
	}
	else
		return (NULL);
	return (cpy);
}
