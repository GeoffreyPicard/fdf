/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:39:40 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/06 12:46:03 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char*)s1)[i] ==
			((unsigned char*)s2)[i] &&
			((unsigned char*)s1)[i] &&
			((unsigned char*)s2)[i] && i < n - 1)
		i++;
	return (((unsigned char*)s1)[i] -
			((unsigned char*)s2)[i]);
}
