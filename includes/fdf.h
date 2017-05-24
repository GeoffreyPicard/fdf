/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:46:58 by gepicard          #+#    #+#             */
/*   Updated: 2016/12/01 09:40:53 by gepicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# define LEFT 700
# define RIGHT -400
# define ROT 0

typedef	struct	s_inttab
{
	int				*tab;
	struct s_inttab *next;
}				t_inttab;

typedef struct	s_t
{
	int			**tab;
	void		*mlx;
	void		*win;
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win_ptr;
	int			endian;
	int			bpp;
	int			sizeline;
	char		*img;
	int			i;
	int			j;
	int			x;
	int			y;
	int			h;
	int			l;
	int			fd;
	int			dx;
	int			dy;
	int			sy;
	int			sx;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			err;
	int			e2;
	int			ecart;
	int			larg;
	int			haut;
	float		relief;
	int			couleur;
	int			id_couleur;
}				t_t;

t_inttab		*ft_create_elem(int *tab);
void			ft_list_push_back(t_inttab *list, int *tab);
int				ft_count_len(char **tab);
int				*ft_tab_to_inttab(char **tab);
char			**ft_char_to_tab(char *line);
t_inttab		*ft_parse(int fd, char **line, int *l);
int				ft_list_size(t_inttab *list);
int				**ft_list_to_tab(t_inttab *list, int h, int l);
char			**ft_char_to_tab(char *line);
int				ft_get_x(int x, int y, int z);
int				ft_get_y(int x, int y, int z);
void			ft_put_main(int **tab, int h, int l, t_t *t);
void			ft_put_pixel_to_img(unsigned long color, t_t *t, int l, int h);
void			ft_put_main_img(t_t *t);
void			ft_li_img(int y0, int x1, int y1, t_t *t);
void			ft_put_line_to_img(t_t *t, int x, int y);
int				ft_couleur(t_t *t);
int				ft_key(int key_code, t_t *t);
int				ft_put_img(t_t *t);
void			ft_init_value(t_t *t);
int				ft_couleur(t_t *t);

#endif
