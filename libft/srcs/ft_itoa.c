/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:49:35 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/07 09:45:44 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_zero(void)
{
	char	*dst;

	if (!(dst = ft_strnew(1)))
		return (NULL);
	dst[0] = '0';
	return (dst);
}

static char		*ft_negative(int n)
{
	unsigned int	i;
	unsigned int	nb;
	char			*dst;

	i = 0;
	nb = 0;
	if (!(dst = ft_strnew(ft_intlen(n + 1))))
		return (NULL);
	nb = -n;
	while (nb > 0)
	{
		dst[i] = '0' + (nb % 10);
		nb = nb / 10;
		i++;
	}
	dst[i] = '-';
	dst[i + 1] = '\0';
	ft_strrev(dst);
	dst[i + 1] = '\0';
	return (dst);
}

char			*ft_itoa(int n)
{
	char	*dst;
	int		i;

	i = 0;
	if (n <= 0)
	{
		if (n == 0)
			dst = ft_zero();
		else
			dst = ft_negative(n);
		return (dst);
	}
	if (!(dst = ft_strnew(ft_intlen(n))))
		return (NULL);
	while (n > 0)
	{
		dst[i] = '0' + (n % 10);
		n = n / 10;
		i++;
	}
	dst[i] = '\0';
	ft_strrev(dst);
	dst[i] = '\0';
	return (dst);
}
