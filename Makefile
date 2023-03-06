# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 12:08:22 by mbaanni           #+#    #+#              #
#    Updated: 2023/03/06 12:23:32 by mbaanni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
MLX= -lmlx -framework OpenGL -framework AppKit# -lmlx -lXext -lX11
CC = cc
SRC = main.c get_next_line.c  get_next_line_utils.c \
f_calloc.c read_map.c file_checke.c ft_split.c  check_ones.c \
ft_putnbr.c fold.c graph.c event.c free_array.c right_left.c up_down.c

BSRC = main_bonus.c free_array.c rand.c check_ones_bonus.c ft_split.c read_map.c \
enemy_cnd.c get_next_line.c right_left_bonus.c event_bonus.c get_next_line_utils.c \
file_checke_bonus.c graph_bonus.c up_down_bonus.c find_enemy.c fold.c f_calloc.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
NAME = so_long
BNAME = so_long_bonus

all : $(NAME)

bonus : $(BNAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)
$(BNAME) : $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) $(MLX) -o so_long
clean :
	@rm -rf *.o
fclean : clean
	@rm -rf so_long so_long_bonus
re : fclean all

.PHONY: all clean fclean re
