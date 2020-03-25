# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyrykuussaari <pyrykuussaari@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 14:34:26 by pkuussaa          #+#    #+#              #
#    Updated: 2020/03/25 13:33:47 by pyrykuussaa      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = lem-in

SRC = src/main.c src/parse.c src/save_paths.c src/result.c src/algorithm.c src/link_rooms.c src/go_through_tunnels.c get_next_line/get_next_line.c ft_printf/libftprintf.a

INC = includes/lemin.h

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re run

all: $(FILE)

$(FILE):
	@echo "Compiling..."
	@cd ft_printf && make && cd ..
	@cd graphics && make re && cd ..
	gcc -I $(INC) -o $(FILE) $(SRC)
	@echo "Done."

clean:
	@echo "cleaning libraries..."
	@cd ft_printf && make clean && cd ..
	@rm -f info_file

fclean: clean
	@echo "removing executables..."
	@cd ft_printf && make fclean && cd ..
	@rm -f $(FILE)

re: fclean all

run:
	rm -f info_file
	touch info_file
	./lem-in < maps/map02 > info_file | graphics/./graphics < info_file
