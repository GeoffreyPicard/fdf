/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:17:00 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/01 09:30:43 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_x(int x, int y, int z)
{
	int	res;
	int	i;

	i = 0;
	(void)z;
	res = x - 1 * y;
	while (i < ROT)
	{
		res = res - 1 * y;
		i++;
	}
	return (res);
}

int		ft_get_y(int x, int y, int z)
{
	int	res;
	int	i;

	i = 0;
	z = -z;
	res = z + x / 2 + y / 2;
	while (i < ROT)
	{
		res = z + x / 2 + res / 2;
		i++;
	}
	return (res);
}

void	ft_li_img(int y0, int x1, int y1, t_t *t)
{
	t->dx = abs(x1 - t->x0);
	t->sx = t->x0 < x1 ? 1 : -1;
	t->dy = abs(y1 - y0);
	t->sy = y0 < y1 ? 1 : -1;
	t->err = (t->dx > t->dy ? t->dx : -(t->dy)) / 2;
	while (1)
	{
		ft_put_pixel_to_img(ft_couleur(t), t, t->x0, y0);
		if (t->x0 == x1 && y0 == y1)
			break ;
		t->e2 = t->err;
		if (t->e2 > -(t->dx))
		{
			t->err -= t->dy;
			t->x0 += t->sx;
		}
		if (t->e2 < t->dy)
		{
			t->err += t->dx;
			y0 += t->sy;
		}
	}
}

void	ft_put_line_to_img(t_t *t, int x, int y)
{
	if (t->i - t->ecart >= (LEFT))
	{
		t->id_couleur = t->tab[t->y][t->x - 1] - t->tab[y][x];
		t->couleur = t->tab[t->y][t->x - 1];
		t->x0 = ft_get_x(t->i - t->ecart, t->j, (t->tab[y][x - 1]) * t->relief);
		ft_li_img(ft_get_y(t->i - t->ecart, t->j,
					(t->tab[y][x - 1]) * t->relief),
				ft_get_x(t->i, t->j, (t->tab[y][x]) * t->relief),
				ft_get_y(t->i, t->j, (t->tab[y][x]) * t->relief), t);
	}
	if (t->j - t->ecart >= RIGHT)
	{
		t->id_couleur = t->tab[y - 1][x] - t->tab[y][x];
		t->couleur = t->tab[t->y - 1][t->x];
		t->x0 = ft_get_x(t->i, t->j - t->ecart, (t->tab[y - 1][x]) * t->relief);
		ft_li_img(ft_get_y(t->i, t->j - t->ecart,
					(t->tab[y - 1][x]) * t->relief),
				ft_get_x(t->i, t->j, (t->tab[y][x]) * t->relief),
				ft_get_y(t->i, t->j, (t->tab[y][x]) * t->relief), t);
	}
}

void	ft_put_main_img(t_t *t)
{
	t->y = 0;
	t->j = RIGHT;
	while (t->j < ((t->h * t->ecart + RIGHT)))
	{
		t->x = 0;
		t->i = LEFT;
		while (t->i < (t->l * t->ecart + LEFT))
		{
			ft_put_line_to_img(t, t->x, t->y);
			t->i += t->ecart;
			t->x++;
		}
		t->y++;
		t->j += t->ecart;
	}
}
