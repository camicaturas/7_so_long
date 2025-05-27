# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cberneri < cberneri@student.42prague.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:55:32 by ohosnedl          #+#    #+#              #
#    Updated: 2024/05/14 09:40:07 by cberneri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################
## ARGUMENTS

NAME	= so_long
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBFT	= ./lib/libft_exp
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

HEADERS := -I ./sources/so_long.h -I $(LIBMLX)/include -I $(LIBFT)
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L$(LIBFT) -lft_expanded
SOURCES	:= $(shell find ./sources -iname "*.c")
OBJECTS	:= ${SOURCES:.c=.o}

################################################
## RULES

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@$(MAKE) -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJECTS)
	@$(CC) $(OBJECTS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)$(NAME) COMPILED!! $(END_COLOR)"

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libmlx libft
