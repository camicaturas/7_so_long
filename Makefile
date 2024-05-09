# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:55:32 by ohosnedl          #+#    #+#              #
#    Updated: 2024/04/09 12:28:30 by cberneri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################
## ARGUMENTS

NAME	= so_long
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
#LIBFT	= libft_expanded
LIBMLX	= ./lib/MLX42
CC = cc

################################################
## COLORS

# Reset
END_COLOR	= \033[0m       # Text Reset

# Regular Colors
BLACK	= \033[0;30m        # Black
RED		= \033[0;31m          # Red
GREEN	= \033[0;32m        # Green
YELLOW	= \033[0;33m       # Yellow
BLUE	= \033[0;34m         # Blue
PURPLE	= \033[0;35m       # Purple
CYAN	= \033[0;36m         # Cyan
WHITE	= \033[0;37m        # White

################################################
## SOURCES

HEADERS	:= -I ./sources/so_long.h -I $(LIBMLX)/include
#LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L./lib/libft -libft_expanded

#para mac
#LIBS	:= $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.4/lib/" -L"/lib/libft -libft_expanded"
#LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBS	:= $(LIBMLX)/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -L"/opt/homebrew/Cellar/glfw/3.4/lib/" -L"/lib/libft -libft_expanded"
#LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L./libraries/get_next_line -lget_next_line -L./libraries/ft_printf -lftprintf

SOURCES	:= $(shell find ./sources -iname "*.c")
OBJECTS	:= ${SOURCES:.c=.o}

################################################
## RULES

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)


$(NAME): $(OBJECTS)
#	@$(CC) $(OBJECTS) $(LIBS) $(HEADERS) -o $(NAME) ${LIBFT}
	@$(CC) $(OBJECTS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)$(NAME) COMPILED!! $(END_COLOR)"


#$(LIBFT):
#	@make all -C $(LIBFT) --no-print-directory

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

#valgrind: $(NAME)
#	valgrind --leak-check=full ./$(NAME)
#test:
#	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME)

.PHONY: all, clean, fclean, re, libmlx