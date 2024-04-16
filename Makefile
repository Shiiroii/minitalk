# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:27:21 by lulm              #+#    #+#              #
#    Updated: 2024/04/16 15:29:02 by lulm             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk.a

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -fr

SRCS =	ft_print_pid		\
		ft_checker			\
		ft_transfer_message	\
		

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
