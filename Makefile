# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/22 21:27:45 by wbeets            #+#    #+#              #
#    Updated: 2013/12/22 21:27:47 by wbeets           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
FILES	= main.c\
		  draw.c\
		  hooks.c
SRC		= $(addprefix src/, $(FILES))
OBJ		= $(SRC:src/%.c=.obj/%.o)
FLAGS	= -Wall -Werror -Wextra
DFLAGS	= -Wall -Werror -Wextra -g3 -pedantic
#LIBCOM	= -L libft -lft -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
LIBCOM	= -L libft -lft -L/usr/X11/lib -lmlx -lXext -lX11 

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
ERROR_COLOR=\x1b[31;01m
WARN_COLOR=\x1b[33;01m
INCLUDE	= -I includes -I libft/includes  -I /usr/X11/include
DEB		= .deb/test

all: $(NAME)

$(NAME): disp lib disp2 $(OBJ)
	@echo "$(OK_COLOR)\t---OBJECTS CREATED---$(NO_COLOR)"
	@echo  "\t---COMPILING---EXECUTABLE---"
	@gcc $(OBJ) $(INCLUDE) $(FLAGS) $(LIBCOM) -o $@
	@echo  "$(OK_COLOR)\t---SUCCES---"
	@echo  "---COMPILATION COMPLETE---$(NO_COLOR)"

disp:
	@echo  "$(WARN_COLOR)---PLEASE-HOLD---COMPILING--- $(NO_COLOR)"

disp2:
	@echo  "\t---COMPILING---OBJECTS---"

.obj/%.o: src/%.c
	@mkdir -p .obj/
	@echo ".\c"
	@gcc $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf .obj/
	@make clean -C libft/

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(DEB)
	@make fclean -C libft/

gdb:
	@mkdir -p .deb/
	@cc -o $(DEB) $(INCLUDE) $(DFLAGS) $(LIBCOM) $(SRC)
	lldb $(DEB)

lib:
	@echo "\t---CHECKING LIBRARY---"
	@make -C libft
	@echo "$(OK_COLOR)\t---LIBRARY UP TO DATE---$(NO_COLOR)"

relib:
	@echo "\t---CHECKING LIBRARY---"
	@make re -C libft
	@echo "$(OK_COLOR)\t---LIBRARY UP TO DATE---$(NO_COLOR)"

re: fclean all

.obj/draw.o: includes/header.h
.obj/main.o: includes/header.h
