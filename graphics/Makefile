# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/25 12:37:31 by pyrykuussaa       #+#    #+#              #
#    Updated: 2020/06/09 13:03:02 by pkuussaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = graphics

SRC = src/main.c src/draw_move.c src/scan.c src/draw_ants.c src/move_ants.c src/events.c src/draw_links.c src/draw.c src/parse.c ../get_next_line/get_next_line.c ../ft_printf/libftprintf.a

INC =  -I includes/graphics.h


FLAGS = -lmlx -framework OpenGL -framework AppKit
#FLAGS = -L.. -lmlx -L/usr/X11/include/../lib -lXext -lX11 -lm -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(FILE)

$(FILE):
	gcc $(FLAGS) $(INC) $(SRC) -o $(FILE)

clean:

fclean: clean
	rm -f $(FILE)

re: fclean all
