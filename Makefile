# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gepicard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 15:49:48 by gepicard          #+#    #+#              #
#    Updated: 2016/12/01 10:02:20 by gepicard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS=-Wall -Wextra -Werror

NAME=fdf

SRC=    main.c\
		ft_parse.c\
		ft_parse2.c\
		ft_list.c\
		ft_print.c\
		ft_env.c\

OBJ=$(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

$(NAME):
	make -C libft/ fclean && make -C libft/
	make -C mlx/ clean && make -C mlx/
	@gcc -c $(FLAGS) $(SRC_POS) -I./libft/includes -I./mlx -I includes
	@gcc ./libft/libft.a ./mlx/libmlx.a -lmlx -framework OpenGL -framework Appkit $(FLAGS) $(OBJ) -I includes -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
	clean:
	rm -rf $(OBJ)
