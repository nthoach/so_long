# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 12:42:36 by honguyen          #+#    #+#              #
#    Updated: 2024/02/17 13:24:16 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = gcc
FLAGS = -Wall -Wextra -Werror -g3

MLX_DIR = libs/mlx/
LIBFT_DIR = libs/libft/

HEADERS = ./so_long.h
INCLUDE = -framework OpenGL -framework AppKit -L$(MLX_DIR) -lmlx -lm
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

CFILES = 1_check_map_all.c 2_check_map_all.c 3_draw_map.c 4_map_solvable.c 5_put_images_move.c 6_user_move.c
SRCS = $(addprefix srcs/, $(CFILES))
SRCS_BONUS = $(addprefix srcs_bonus/, $(CFILES))

SRC = $(SRCS) so_long.c
SRC_BONUS = $(SRCS_BONUS) so_long.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -I$(MLX_DIR) -c $< -o $@

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)

all: $(NAME)

bonus: $(OBJ_BONUS)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

play: all
	./$(NAME) map.ber

playbonus: bonus
	./$(NAME_BONUS) map.ber

test:
	@make $(NAME)
	@./$(NAME) map.ber

leaks:
	@make $(NAME)
	@valgrind -s --leak-check=full --show-leak-kinds=all ./$(NAME) map.ber

	
clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all bonus

.PHONY: all clean fclean re bonus play
