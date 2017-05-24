/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:27:20 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/01 09:59:39 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel_to_img(unsigned long color, t_t *t, int l, int h)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0x00FF00) >> 8);
	b = (color & 0x0000FF);
	if (l >= 0 && l < 2300 && h >= 0 && h < 1300)
	{
		t->img[h * t->sizeline + l * t->bpp / 8] = b;
		t->img[h * t->sizeline + l * t->bpp / 8 + 1] = g;
		t->img[h * t->sizeline + l * t->bpp / 8 + 2] = r;
	}
}

int		ft_put_img(t_t *t)
{
	t->img_ptr = mlx_new_image(t->mlx_ptr, 2300, 1300);
	t->img = mlx_get_data_addr(t->img_ptr, &(t->bpp),
			&(t->sizeline), &(t->endian));
	ft_put_main_img(t);
	mlx_clear_window(t->mlx_ptr, t->win_ptr);
	mlx_put_image_to_window(t->mlx_ptr, t->win_ptr,
			t->img_ptr, t->larg, t->haut);
	mlx_destroy_image(t->mlx_ptr, t->img);
	return (0);
}

void	ft_image(t_t *t)
{
	t->mlx_ptr = mlx_init();
	t->win_ptr = mlx_new_window(t->mlx_ptr, 2300, 1300, "fdf");
	mlx_expose_hook(t->win_ptr, ft_put_img, t);
	mlx_key_hook(t->win_ptr, ft_key, t);
	mlx_loop(t->mlx_ptr);
}

void	ft_init_value(t_t *t)
{
	if ((t->h >= 0 && t->h <= 20) || (t->l >= 0 && t->l <= 20))
		t->ecart = 50;
	else if ((t->h > 20 && t->h < 40) || (t->l > 20 && t->l < 40))
		t->ecart = 17;
	else if ((t->h >= 40 && t->h <= 100) || (t->l >= 40 && t->l <= 100))
		t->ecart = 10;
	else if ((t->h > 100 && t->h < 300) || (t->l > 100 && t->l < 300))
		t->ecart = 4;
	else if ((t->h >= 300 && t->h < 1000) || (t->l >= 300 && t->l < 1000))
		t->ecart = 2;
	else
		t->ecart = 1;
	t->relief = 1;
	t->larg = 0;
	t->haut = 0;
}

int		main(int ac, char **av)
{
	t_t			*t;
	char		*line;
	t_inttab	*list;

	if (ac == 2)
	{
		t = malloc(sizeof(t_t));
		if (!(t->fd = open(av[1], O_RDONLY)))
		{
			ft_putstr("open error\n");
			return (1);
		}
		list = ft_parse(t->fd, &line, &(t->l));
		t->h = ft_list_size(list);
		t->tab = ft_list_to_tab(list, t->h, t->l);
		ft_init_value(t);
		ft_image(t);
		if (close(t->fd) == -1)
		{
			ft_putstr("close error\n");
			return (1);
		}
	}
	return (0);
}
