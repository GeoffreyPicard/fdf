/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:50:51 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/04 09:07:08 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (((unsigned char*)s1)[i] ==
			((unsigned char*)s2)[i] &&
			((unsigned char*)s1)[i] &&
			((unsigned char*)s2)[i])
		i++;
	return (((unsigned char*)s1)[i] -
			((unsigned char*)s2)[i]);
}
