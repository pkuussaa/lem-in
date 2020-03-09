# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 14:34:26 by pkuussaa          #+#    #+#              #
#    Updated: 2020/03/09 17:09:08 by pkuussaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = lem-in

SRC = src/main.c src/parse.c src/link_rooms.c get_next_line/get_next_line.c ft_printf/libftprintf.a

INC = includes/lemin.h

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(FILE)

$(FILE):
	@echo "Compiling..."
	@cd ft_printf && make && cd ..
	gcc -I $(INC) -o $(FILE) $(SRC)
	@echo "Done."

clean:
	@echo "cleaning libraries..."
	@cd ft_printf && make clean && cd ..

fclean: clean
	@echo "removing executables..."
	@cd ft_printf && make fclean && cd ..
	@rm -f $(FILE)

re: fclean all
