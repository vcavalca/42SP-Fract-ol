# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 15:44:46 by vcavalca          #+#    #+#              #
#    Updated: 2021/09/02 10:21:54 by vcavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Werror -Wextra
CC = clang $(CFLAGS)
LINUX_FLAGS =  -lft -lXext -lX11 -lmlx
LINUX_INCLUDE = -I$(MINILIBX_DIRECTORY)

INCLUDE_DIR = includes/
SOURCES_DIRECTORY = sources/
OBJECTS_DIRECTORY = objects/

LIBFT_DIRECTORY = $(INCLUDE_DIR)libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

MINILIBX_DIRECTORY = $(INCLUDE_DIR)minilibx-linux/
MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

VALGRIND = valgrind --leak-check=full -q

HEADERS_DIRECTORY = $(INCLUDE_DIR)
HEADERS_FILES = fractol.h			\
				error_messages.h	\
				key_linux.h			\
				screen_setup.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_FILES))

SOURCES_FILES =	fractol.c	\
				utils.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_FILES))

OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_FILES))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(OBJECTS) -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) $(LINUX_FLAGS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) -c $(LINUX_INCLUDE) $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIRECTORY)

$(MINILIBX):
	@make -C $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re: fclean all
