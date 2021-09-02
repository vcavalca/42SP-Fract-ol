# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 15:44:46 by vcavalca          #+#    #+#              #
#    Updated: 2021/09/02 04:29:34 by vcavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INCLUDE_DIR = includes
SRC_DIR = sources
OBJ_DIR = obj
LIBFT_DIR = libft
MLX_DIR = minilibx-linux

LIBFT = $(INCLUDE_DIR)/$(LIBFT_DIR)/libft.a

MLX = $(INCLUDE_DIR)/$(MLX_DIR)/libmlx.a

VALGRIND = valgrind --leak-check=full -q

HEADERS = $(INCLUDE_DIR)/fractol.h

SRC_FILES = fractol.c					\
			utils.c


SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wall -Werror -Wextra
CC = clang $(CFLAGS)
LIBFLAGS = -Lmlx_Linux -L$(INCLUDE_DIR)/$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC)  $(OBJ) -L$(LIBFT_DIR) -L$(MLX_DIR) $(LIBFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p obj
	$(CC) -c -I$(INCLUDE_DIR) -o $@ $<

$(LIBFT):
	make -C $(INCLUDE_DIR)/$(LIBFT_DIR)

$(MLX):
	make -C $(INCLUDE_DIR)/$(MLX_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean
	@make -C $(INCLUDE_DIR)/$(MLX_DIR) clean
	@make -C $(INCLUDE_DIR)/$(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: $(LIBFT)
