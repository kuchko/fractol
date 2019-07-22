# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okuchko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 16:03:56 by okuchko           #+#    #+#              #
#    Updated: 2019/01/16 16:05:31 by okuchko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

OBJ_DIR = ./obj/

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

SOURCES = main.c ft_draw.c draw_julia.c ft_puts.c ft_keys.c ft_threads.c
# ft_valid.c ft_fdf_addons.c ft_draw.c ft_fdf_init.c \
#		ft_modify_view.c ft_modify_wire.c ft_puts.c ft_keys.c

OBJECTS = $(addprefix $(OBJ_DIR), $(SOURCES:.c=.o))

# minilibx

# LIBX_DIR = minilibx/
# LIBX_INC_FLAGS = -L $(LIBX_DIR) -lmlx
# LIBX_HEADER_FLAGS =	-I $(LIBX_DIR)
LIBX_FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit

# libft

INC = $(INC_DIR)libft.a
INC_DIR = libft/
INCLUDES = $(INC_DIR)inc/
INC_FLAGS = -L $(INC_DIR) -lft
HEADER_FLAGS =	-I $(INCLUDES) -I fractol.h


all: $(NAME)

$(NAME): $(INC) $(OBJECTS)
	# $(CC) $(CC_FLAGS) $(OBJECTS) $(INC_FLAGS) $(LIBX_INC_FLAGS) $(LIBX_HEADER_FLAGS) $(LIBX_FRAMEWORKS) -o $(NAME)
	$(CC) $(CC_FLAGS) $(OBJECTS) $(INC_FLAGS) $(LIBX_FRAMEWORKS) -o $(NAME)
$(INC):
	make -C $(INC_DIR)

$(OBJECTS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		$(CC) $(CC_FLAGS) -c $< -o $@ $(HEADER_FLAGS)

clean:
	@rm -rf $(OBJ_DIR)
	make clean -C $(INC_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf leaks
	make fclean -C $(INC_DIR)

re:	fclean all
