# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 15:44:46 by vcavalca          #+#    #+#              #
#    Updated: 2021/08/24 14:46:19 by vcavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFT = libft
LIBFT_LIB = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror  -I/usr/include -Imlx_linux -O3
AR = ar rc
RM = rm -f

FT_FILES = main

RUN_DIR = ./
RUN = $(addprefix $(RUN_DIR), $(addsuffix .c, $(FT_FILES)))

RUN_O = $(addprefix $(RUN_DIR), $(addsuffix .o, $(FT_FILES)))

.c.o: $(RUN)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(RUN_O)
	make all -C$(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $@ $^

all: $(NAME)

clean: 
	$(RM) $(RUN_O)
	make fclean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
