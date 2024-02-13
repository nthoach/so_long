# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 12:42:36 by honguyen          #+#    #+#              #
#    Updated: 2024/02/13 13:25:16 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror -g3

MLX_DIR = libs/mlx/
LIBFT_DIR = libs/libft/

HEADERS = ./so_long.h
INCLUDE = -framework OpenGL -framework AppKit -L$(MLX_DIR) -lmlx
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

MAP = check_map_all.c draw_map.c map_solvable.c
SRC_MAP = $(addprefix src_map/, $(MAP))

MOV = put_images_move.c user_move.c msg_err.c
SRC_MOV = $(addprefix src_mov/, $(MOV))

SRC = $(SRC_MAP) $(SRC_MOV) so_long.c

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I$(MLX_DIR) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

bonus: all

play: all
	./$(NAME) map.ber

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus play
