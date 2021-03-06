# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 17:20:28 by ymohl-cl          #+#    #+#              #
#    Updated: 2014/03/24 21:50:35 by ymohl-cl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAG = -Wall -Wextra -Werror

INC = -I includes

SRC =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strlcat.c \
		ft_putstr.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstiter.c \

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o : %.c
	@$(CC) $(FLAG) -o $@ -c $< $(INC)
	@echo "\033[32m.\c\033[0m"

$(NAME): say $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32m\tDONE !\033[0m"

say:
	@echo "\033[33m  '.' == One file is compiled\t\033[0m"
	@echo "\033[33m  ' ' == make: Nothing to be done for 'all'\t\033[0m"
	@echo "\033[32m  Libft compilation progress\t\c\033[0m"

clean:
	@rm -f $(OBJ)
	@echo "\033[32m  Remove all objects from the Libft\tDONE !\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32m  Remove libft.a\t\t\t\tDONE !\033[0m"

re: fclean all
