/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:12:11 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/01 09:38:30 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int key_code, t_t *t)
{
	if (key_code == 69)
		t->ecart += 4;
	else if (key_code == 78)
		t->ecart -= 4;
	else if (key_code == 92)
		t->relief++;
	else if (key_code == 88)
		t->relief--;
	else if (key_code == 125)
		t->haut += 50;
	else if (key_code == 126)
		t->haut -= 50;
	else if (key_code == 123)
		t->larg -= 50;
	else if (key_code == 124)
		t->larg += 50;
	else if (key_code == 49)
		ft_init_value(t);
	else if (key_code == 53)
		exit(1);
	ft_put_img(t);
	return (0);
}

int		ft_couleur(t_t *t)
{
	int res;
	int i;

	i = 0;
	res = 0x00FFFFFF;
	if (t->couleur == 0)
		res = 0x3399ff;
	else if (t->couleur >= 0 && t->couleur <= 100)
		res = 0x666600;
	else if (t->couleur > 100)
		res = 0x00FFFFFF;
	else if (t->couleur < 0 && t->couleur >= 10)
		res = 0x3399ff;
	else if (t->couleur < 10)
		res = 0x3399ff;
	else
		res = 0x00FFFFFF;
	if (t->id_couleur > 0 && i / 3 == 0)
		t->couleur--;
	return (res);
}
