# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:27:21 by lulm              #+#    #+#              #
#    Updated: 2024/04/22 09:09:02 by lionelulm        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk.a

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -fr

SRCS =	server.c		\
		client.c


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
