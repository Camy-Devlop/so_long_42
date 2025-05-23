# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isadbaib <isadbaib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 08:37:37 by isadbaib          #+#    #+#              #
#    Updated: 2025/04/15 22:13:01 by isadbaib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_SRC = ./libft/
LIBFT = $(LIBFT_SRC)libft.a
LIBX_SRC = ./minilibx-linux/
LIBX = $(LIBX_SRC)libmlx.a
LIBX_LINUX = $(LIBX_SRC)libmlx_Linux.a
SRC =./src/so_long.c \
		./src/backtrack/ft_back_traking.c \
		./src/backtrack/ft_back_traking_c.c \
		./src/player/ft_search_gamer.c \
		./src/ft_card/ft_copy_card.c \
		./src/check/ft_check_file.c \
		./src/check/ft_check_read_end_file.c \
		./src/check/ft_check_t_map.c \
		./src/ft_free/ft_free_t_window.c \
		./src/error/ft_error_windows.c \
		./src/design/ft_point.c \
		./src/error/ft_error_file.c \
		./src/error/ft_error_t_map.c \
		./src/error/ft_error_t_card.c \
		./src/error/ft_error_allowance.c \
		./src/error/ft_error_image.c \
		./src/error/ft_error_coord.c \
		./src/error/ft_error_gamer.c \
		./src/error/ft_error_load_file_xpm.c \
		./src/ft_free/ft_free_t_map.c \
		./src/ft_free/ft_free_t_card.c \
		./src/ft_free/ft_free_coord.c \
		./src/ft_free/ft_free_gamer.c \
		./src/ft_free/ft_free_room.c \
		./src/ft_free/ft_free_all.c \
		./src/file/ft_file.c \
		./src/ft_card/ft_card.c \
		./src/draw/ft_draw.c \
		./src/draw/ft_draw_map.c \
		./src/ft_rules/ft_move_up.c \
		./src/ft_rules/ft_move_down.c \
		./src/ft_rules/ft_move_left.c \
		./src/ft_rules/ft_move_right.c \
		./src/ft_rules/ft_move_player.c \
		./src/event/ft_close.c \
		./src/event/ft_key_move.c \
		./src/image/ft_image.c \
		./src/window/ft_window.c

#UNAME_S := $(shell uname -s)
#ifeq ($(UNAME_S),Linux)
#    ifeq ($(shell lsb_release -si),Debian)
#        include Makefile.debian
#    else
#        include Makefile.other
#    endif
#else
#    include Makefile.other
#endif

CC = cc 
FLAGS = -Wall -Wextra -Werror -g3 -O0
NAME = so_long 
RM = rm
OBJ = ${SRC:.c=.o}

all : $(NAME) $(LIBFT) $(LIBX) $(LIBX_LINUX)

$(NAME) : ${OBJ} $(LIBFT) $(LIBX)
	@$(CC) $(OBJ) -o $(NAME) $(FLAGS) -L$(LIBFT_SRC) -lft -I$(LIBX_SRC) -L$(LIBX_SRC) -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

${LIBFT} : 
	@$(MAKE) -C $(LIBFT_SRC) all

${LIBX} : $(LIBX_SRC) 
	@$(MAKE) -C $(LIBX_SRC)

%.o : %.c
	@$(CC) -c $< $(FLAGS) -I$(LIBFT_SRC)include -I$(LIBX_SRC) -o $@ 

clean : 
	$(RM) -f $(OBJ) 
	$(MAKE) -C $(LIBFT_SRC) clean
	$(MAKE) -C $(LIBX_SRC) clean

fclean : clean 
	$(RM) -f $(NAME)
	$(MAKE) -C $(LIBFT_SRC) fclean
	$(MAKE) -C $(LIBX_SRC) clean

re : fclean all

.PHONY: all clean fclean re

