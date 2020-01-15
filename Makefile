# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 19:43:49 by spalmer           #+#    #+#              #
#    Updated: 2020/01/12 18:09:31 by spalmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

SRC = ./src/read.c\
	./src/lines.c\
	./src/dops.c\
	./src/main.c

#SRC = read.c lines.c dops.c
	
#SRC_DIR = ./src/

#OBJ = $(SRC:.c=.o)

OBJ = read.o lines.o dops.o main.o
INC = -I ./src/

LIBRARIES = -lmlx -lm -lft -L $(LIBFT_DIR) -L $(LIBX_DIR) -framework OpenGL -framework AppKit
INCLUDES = $(LIBFT_DIR) $(LIBX_DIR) $(INC)

LIBFT_DIR = ./src/libft/
INC_FT = -I $(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)libft.a

LIBX_DIR = ./src/minilibx_macos/
INC_FT = -I $(LIBX_DIR)
LIBX = $(LIBX_DIR)libmlx.a

all: $(LIBFT) $(LIBX) $(NAME)

$(OBJ):
	gcc $(FLAGS) $(SRC) -c -g
$(LIBFT):
	make -C $(LIBFT_DIR)
$(LIBX):
	make -C $(LIBX_DIR)
$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBRARIES) -o $(NAME)

clean:

	make -C $(LIBFT_DIR) clean
	make -C $(LIBX_DIR) clean
	rm 	$(OBJ)

fclean: clean

	rm $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re
