# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 18:56:58 by vcavalca          #+#    #+#              #
#    Updated: 2021/05/25 17:12:18 by vcavalca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c99
AR = ar rc
RM = rm -f

FT_FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove \
		ft_memchr ft_memcmp ft_strlen ft_strlcpy ft_strlcat \
		ft_strchr ft_strrchr ft_strnstr ft_strncmp ft_atoi \
		ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
		ft_toupper ft_tolower ft_calloc ft_strdup ft_substr \
		ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi \
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
		ft_putchar ft_putstr ft_strcat ft_strcpy ft_strcmp \
		ft_strstr ft_strncpy ft_strncat ft_strmalloc ft_putnbr \

FT_FILES_BONUS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
		ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

RUN_DIR = ./
RUN = $(addprefix $(RUN_DIR), $(addsuffix .c, $(FT_FILES)))
RUN_BONUS = $(addprefix $(RUN_DIR), $(addsuffix .c, $(FT_FILES_BONUS)))

RUN_DIR_O = ./
RUN_O = $(addprefix $(RUN_DIR_O), $(addsuffix .o, $(FT_FILES)))
RUN_O_BONUS = $(addprefix $(RUN_DIR_O), $(addsuffix .o, $(FT_FILES_BONUS)))

.c.o: $(RUN)
	$(CC) $(FLAGS) -c -o $@ $<

$(NAME): $(RUN_O)
	$(AR) $@ $^

bonus: $(RUN_O_BONUS)
	$(AR) $(NAME) $^

all: $(NAME)

clean: 
	$(RM) $(RUN_O) $(RUN_O_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
