# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/19 11:28:49 by hbruvry           #+#    #+#              #
#    Updated: 2018/06/12 10:52:35 by hbruvry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		sources/main.c \
			sources/ft_getmlx.c \
			sources/ft_getctrl.c \
			sources/ft_getenv.c \
			sources/ft_drawthread.c \
			sources/ft_drawfract.c \
			sources/ft_drawtext.c \
			sources/ft_fractcontrol.c \
			sources/ft_keycontrol.c

OBJS =		$(SRCS:.c=.o)

NAME =		fractol

MLX =		-L /usr/X11/lib/ -lmlx -framework OpenGl -framework Appkit

// MLX =		-L /usr/local/lib/ -lmlx -framework OpenGl -framework Appkit

CC =		clang

CFLAGS =	-Wall -Wextra -Werror

LIBFT =		libft

_GREEN =	$ \033[32m
_YELLOW =	$ \033[33m
_RED =		$ \033[31m
_END =		$ \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@gcc -lpthread $(CFLAGS) -o $(NAME) -I /usr/local/include/ $(OBJS) libft/libft.a $(MLX)
	@echo "$(_GREEN)fractol compiled$(_END)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT)
	@rm -f $(OBJS)
	@echo "libft cleaned"
	@echo "fractol cleaned"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@rm -f $(NAME)
	@echo "fractol fcleaned"

re: fclean all

.PHONY: libft clean fclean all re
