# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/25 12:37:31 by pyrykuussaa       #+#    #+#              #
#    Updated: 2020/06/03 15:41:45 by pkuussaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = graphics

SRC = src/main.c src/scan.c src/events.c src/draw.c src/parse.c ../get_next_line/get_next_line.c ../ft_printf/libftprintf.a

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
