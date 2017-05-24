/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:37:34 by gepicard          #+#    #+#             */
/*   Updated: 2016/11/13 10:42:51 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_word(char const *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			word++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		t[2];

	i = -1;
	t[0] = 0;
	t[1] = 0;
	if (!s || !c)
		return (NULL);
	if ((!(tab = (char **)malloc(sizeof(*tab) * ft_count_word(s, c) + 1))))
		return (NULL);
	while (i++ < ft_count_word(s, c) - 1)
	{
		while (s[t[1]] == c && s[t[1]])
		{
			t[1]++;
			t[0]++;
		}
		while (s[t[0]] != c && s[t[0]])
			t[0]++;
		tab[i] = ft_strsub(s, t[1], (t[0] - t[1]));
		t[1] = t[0];
	}
	tab[i] = 0;
	return (tab);
}
