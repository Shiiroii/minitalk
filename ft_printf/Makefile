# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liulm <liulm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 12:02:13 by liulm             #+#    #+#              #
#    Updated: 2024/11/04 14:58:41 by liulm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc

FLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

SRCS	=	ft_hex.c			\
			ft_printf.c			\
			ft_put_chars.c		\
			ft_put_numbers.c

OBJS	= ${SRCS:.c=.o}

all: ${NAME}

${NAME}:	${OBJS}
	@ar rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
