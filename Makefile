# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 14:34:26 by pkuussaa          #+#    #+#              #
#    Updated: 2020/10/05 15:34:41 by pkuussaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE = lem-in

SRC = src/main.c src/other.c src/parse_flags.c src/short_path.c src/init.c src/result_path_init.c src/count_path_moves.c src/parse.c src/navigate_moves.c src/free_memory.c src/queue.c src/help_functions.c src/save_paths.c src/result.c src/algorithm.c src/link_rooms.c src/go_through_tunnels.c get_next_line/get_next_line.c ft_printf/libftprintf.a

INC = includes/lemin.h

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re run

all: $(FILE)

$(FILE):
	@echo "Compiling..."
	@cd ft_printf && make && cd ..
	@cd graphics && make re && cd ..
	gcc $(FLAGS) -I $(INC) -o $(FILE) $(SRC)
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
	./lem-in -p < maps/valid/shortpath.map > info_file | graphics/./graphics < info_file
