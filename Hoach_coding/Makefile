# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 12:42:36 by honguyen          #+#    #+#              #
#    Updated: 2024/02/16 07:39:22 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror -g3

MLX_DIR = libs/mlx/
LIBFT_DIR = libs/libft/

HEADERS = ./so_long.h
INCLUDE = -framework OpenGL -framework AppKit -L$(MLX_DIR) -lmlx
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

CFILES = check_map_all_1.c check_map_all_2.c draw_map.c map_solvable.c put_images_move.c user_move.c
SRCS = $(addprefix srcs/, $(CFILES))

SRC = $(SRCS) so_long.c

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I$(MLX_DIR) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME) -D BONUS=0

all: $(NAME)

bonus: $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME_BONUS) -D BONUS=1

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
