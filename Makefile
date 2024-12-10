# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liulm <liulm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 11:32:03 by liulm             #+#    #+#              #
#    Updated: 2024/12/03 11:42:35 by liulm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

SERVER = server
CLIENT = client

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

RM = rm -rf

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
		$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(CLIENT)

$(LIBFT):
		$(MAKE) -C ./libft

$(PRINTF):
		$(MAKE) -C ./ft_printf

clean:
		rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
		$(MAKE) -C ./libft fclean
		$(MAKE) -C ./ft_printf fclean

fclean: clean
		rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
