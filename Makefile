# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 15:44:46 by vcavalca          #+#    #+#              #
#    Updated: 2021/08/31 15:44:05 by vcavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIBFT_DIR = libft
LIBFT= $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

OBJ_DIR = obj

HEADER = fractol.h

FT_FILES = main.c

SRC = $(FT_FILES)
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

FLAGS = -Wall -Wextra -Werror -Imlx
CC = clang $(FLAGS)
LIB_FLAGS = -lft -lXext -lX11 -lmlx 

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(OBJ) -L$(LIBFT_DIR) -L$(MLX_DIR) $(LIB_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC) $(HEADER)
	@mkdir obj -p obj
	$(CC) -c -o $@ $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean: 
	$(RM) $(OBJ)

fclean: clean
	@make -C $(MLX_DIR) clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
