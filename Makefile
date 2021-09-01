# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 15:44:46 by vcavalca          #+#    #+#              #
#    Updated: 2021/08/31 21:00:47 by vcavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INCLUDES_DIR = ./includes
MLX_LINUX = $(INCLUDES_DIR)/minilibx-linux

CC = gcc
CFLAGS = -g3 -Wall -Werror -Wextra

LINUX_FLAGS = -Lmlx_linux -L $(MLX_LINUX) -lmlx_linux -lXext -lX11 -lm -lz
LINUX_INCLUDE = -I $(MLX_LINUX)

LIBS = includes/libft/libft.a

SRCS = sources/fractol.c\
	sources/utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBS)
	$(MLX_LINUX)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LINUX_INCLUDE) $(LINUX_FLAGS) $(LIBS)

$(LIBS):
	$(MAKE) -C includes/libft/

$(MLX_LINUX):
	$(MAKE) -C $(MLX_LINUX)

clean:
	rm -rf $(OBJS)
	$(MAKE) fclean -C includes/libft/

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
