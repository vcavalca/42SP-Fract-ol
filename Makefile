# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 15:44:46 by vcavalca          #+#    #+#              #
#    Updated: 2021/09/21 07:05:34 by vcavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = clang
CFLAGS = -c -Wall -Werror -Wextra

SRCS = sources/ft_fractol.c sources/ft_utils.c sources/ft_fractal_mandelbrot.c sources/ft_fractal_julia.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C includes/libft
		@make -C includes/minilibx-linux
		@$(CC) $(OBJ) -o $(NAME) -lXext -lX11 -lm includes/minilibx-linux/libmlx_Linux.a includes/libft/libft.a 
		@echo "Successfully compiled $(NAME)"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ $<

clean: 
		@rm -rf $(OBJ)
		@make clean -C includes/libft
		@echo "Removed objects files"

fclean: clean
		@rm -rf $(NAME)
		@make clean -C includes/minilibx-linux
		@make fclean -C includes/libft
		@echo "Removed $(NAME) file"

re: fclean all
