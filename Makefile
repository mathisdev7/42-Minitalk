# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 17:28:25 by mazeghou          #+#    #+#              #
#    Updated: 2024/11/20 17:28:25 by mazeghou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

SRCS_SERVER = srcs/server/main.c
SRCS_CLIENT = srcs/client/main.c
SRCS_UTILS = srcs/client/utils.c
SRCS_SERVER_BONUS = srcs/server/main_bonus.c
SRCS_CLIENT_BONUS = srcs/client/main_bonus.c

PRINTF_DIR = printf
LIBFT_DIR = libft
GNL_DIR = get_next_line

PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
GNL_LIB = $(GNL_DIR)/gnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB) $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(GNL_LIB):
	make -C $(GNL_DIR)

$(NAME_SERVER): $(SRCS_SERVER) $(SRCS_UTILS) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRCS_SERVER) $(SRCS_UTILS) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB)

$(NAME_CLIENT): $(SRCS_CLIENT) $(SRCS_UTILS) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRCS_CLIENT) $(SRCS_UTILS) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB)

$(NAME_SERVER_BONUS): $(SRCS_SERVER_BONUS) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB)
	$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(SRCS_SERVER_BONUS) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB)

$(NAME_CLIENT_BONUS): $(SRCS_CLIENT_BONUS) $(SRCS_UTILS) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(SRCS_CLIENT_BONUS) $(SRCS_UTILS) $(PRINTF_LIB) $(LIBFT_LIB) $(GNL_LIB)

clean:
	make -C $(PRINTF_DIR) clean
	make -C $(LIBFT_DIR) clean
	make -C $(GNL_DIR) clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
