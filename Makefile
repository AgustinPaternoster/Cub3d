.PHONY: all re clean fclean bonus

# Program file name
NAME	= cub3D

# Compiler and compilation flags
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall #-g
LFLAGS	= -Llibft -lft -Lminilibx -lmlx

# Minilibx linux
MLX_PATH	= minilibx/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Sources
SRC_PATH 	= ./src/
SRC			= 	main.c get_map.c prints.c frees.c check_map.c check_map_utils.c \
				resources.c resources_utils.c dda_algorithm.c events.c \
				math_fn.c render_fn.c texture_fn.c events_utils.c \
				render_utils.c check_map_utils_2.c dda_algorithm_2.c \
				get_map_2.c resources_utils_2.c resources_utils_3.c \
				check_map_utils_3.c
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Includes
INC			=	-I ./inc/\
				-I ./libft/\
				-I ./minilibx/
HEADER		=	inc/cub3d.h


# Main rule
all: library $(MLX) $(NAME)

# Project file rule
$(NAME):$(LIBFT) $(SRCS) $(HEADER) Makefile
	$(CC) $(SRCS) $(CFLAGS) $(LFLAGS) $(INC) -lXext -lX11 -lm  -o $@ 


# Libft rule
library:
	make -C $(LIBFT_PATH)

# MLX rule
$(MLX):
	make -sC $(MLX_PATH)


# Clean up build files rule
clean:
	#rm -rf $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

# Remove program executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

# Clean + remove executable
re: fclean all
