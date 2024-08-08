# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timatias <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 10:54:05 by timatias          #+#    #+#              #
#    Updated: 2024/07/31 13:53:24 by timatias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "fractol"

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
SRC_LIBFT = libft
OBJ_DIR = objs

MLX_DIR = minilibx-linux

SRC = $(SRC_DIR)/eventos.c $(SRC_DIR)/main.c $(SRC_DIR)/mandelbrot.c $(SRC_DIR)/julia.c $(SRC_DIR)/cor_map.c $(SRC_DIR)/eventos2.c $(SRC_DIR)/fechar_janela.c $(SRC_DIR)/ft_atodbl.c $(SRC_DIR)/ft_strcmp.c


OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS = $(SRC:$(SRC_LIBFT)/%.c=$(OBJ_DIR)/%.o)

INCLUDES = -I includes -I $(MLX_DIR)
LIBS = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)
	@echo "Linking $(NAME)..."
	@echo "\033[32mOperacao Completa Engenheiro Timatias!\033[0m

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	@echo "Limpando os arquivos objectos..."
	rm -rf $(OBJ_DIR)

fclean: clean
	@echo "Limpeza geral..."
	rm -f $(NAME)

re: fclean all

