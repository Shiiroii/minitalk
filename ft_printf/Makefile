# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 07:16:48 by lulm              #+#    #+#              #
#    Updated: 2024/02/01 11:25:18 by lulm             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -fr

SRCS =	ft_hexvoid.c	\
		ft_printf.c		\
		ft_putchar.c	\
		ft_puthexa.c	\
		ft_putnbr.c		\
		ft_putnbr_di.c	\
		ft_putstr.c		\
		ft_strlen.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
