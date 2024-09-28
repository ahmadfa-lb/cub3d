# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 14:35:51 by afarachi          #+#    #+#              #
#    Updated: 2024/09/29 01:10:07 by afarachi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC_DIR = srcs
OBJ_DIR = obj
INCLUDE_DIR = includes
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LINK = -L$(MLX_DIR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INCLUDE_DIR)

SRCS = $(SRC_DIR)/data_init/data_init.c \
		$(SRC_DIR)/data_init/get_images_addr.c \
		$(SRC_DIR)/data_init/load_mlx.c \
		$(SRC_DIR)/errors_handling/exit.c \
		$(SRC_DIR)/exit/exit_messages/exit_messages1.c \
		$(SRC_DIR)/exit/exit_messages/exit_messages2.c \
		$(SRC_DIR)/exit/exit_messages/exit_messages3.c \
		$(SRC_DIR)/exit/exit_messages/exit_messages4.c \
		$(SRC_DIR)/exit/exit_messages/exit_messages5.c \
		$(SRC_DIR)/exit/free_all.c \
		$(SRC_DIR)/graphics/floor_and_ceiling.c \
		$(SRC_DIR)/graphics/minimap.c \
		$(SRC_DIR)/graphics/raycasting.c \
		$(SRC_DIR)/graphics/walls_textures.c \
		$(SRC_DIR)/graphics_utils/graphics_utils.c \
		$(SRC_DIR)/graphics_utils/put_pixels.c \
		$(SRC_DIR)/graphics_utils/utils.c \
		$(SRC_DIR)/keys/key_controls.c \
		$(SRC_DIR)/keys/process_motion.c \
		$(SRC_DIR)/keys/process_turn.c \
		$(SRC_DIR)/parsing/check_map_validity.c \
		$(SRC_DIR)/parsing/extract_settings.c \
		$(SRC_DIR)/parsing/parsing_utils.c \
		$(SRC_DIR)/parsing/parsing.c \
		$(SRC_DIR)/parsing/save_colors.c \
		$(SRC_DIR)/parsing/save_essential_settings.c \
		$(SRC_DIR)/parsing/save_map.c \
		$(SRC_DIR)/parsing/save_player_position.c \
		$(SRC_DIR)/parsing/save_textures.c \
		${SRC_DIR}/render.c \
		${SRC_DIR}/game_algorithm.c	\
		${SRC_DIR}/cub3d.c

OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_DIR)/libmlx.a
	@echo "Linking..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LINK) $(LIBFT_LIB) -o $(NAME)
	@echo "Compilation completed."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)  # Create the necessary directories
	@echo -n "Compiling $<... "; \
	$(CC) $(CFLAGS) -c $< -o $@; \
	echo "done."

$(LIBFT_LIB):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "Libft compilation completed."

$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

clean:
	@echo "Cleaning up..."
	@rm -rf $(OBJ_DIR) 
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Clean completed."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
