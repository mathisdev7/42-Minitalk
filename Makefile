# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 17:28:25 by mazeghou          #+#    #+#              #
#    Updated: 2024/11/18 17:28:25 by mazeghou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = srcs/server/main.c
SRCS_CLIENT = srcs/client/main.c

PRINTF_DIR = printf
LIBFT_DIR = libft

PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(PRINTF_LIB) $(LIBFT_LIB) $(NAME_SERVER) $(NAME_CLIENT)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(NAME_SERVER): $(SRCS_SERVER) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRCS_SERVER) $(PRINTF_LIB) $(LIBFT_LIB)

$(NAME_CLIENT): $(SRCS_CLIENT) $(PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRCS_CLIENT) $(PRINTF_LIB) $(LIBFT_LIB)

clean:
	make -C $(PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
