# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 17:47:21 by pkuussaa          #+#    #+#              #
#    Updated: 2020/01/20 15:00:00 by pkuussaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HDR = -I includes/ft_printf.h
FLAGS = -Wall -Wextra -Werror
SRCS = srcs/

OBJ = srcs/check_arg_type.c srcs/check_period.c srcs/ft_printf.c srcs/initialize_rest.c srcs/print_char.c srcs/print_plus.c srcs/print_zeros.c srcs/check_flags.c srcs/check_width.c srcs/get_nbr_count.c srcs/itoa_base.c srcs/print_int.c srcs/print_pointer.c srcs/set_values.c srcs/check_modifier_type.c srcs/choose_printed_arg.c srcs/hype_itoa.c srcs/parse_variables.c srcs/print_min_width.c srcs/print_string.c srcs/print_double.c srcs/print_octal.c srcs/print_percent.c srcs/print_u.c srcs/print_hexa.c srcs/itoa_base_capital.c srcs/input_int.c srcs/int_period.c srcs/input_double.c

FILES_O = check_arg_type.o check_flags.o check_modifier_type.o check_period.o check_width.o choose_printed_arg.o ft_printf.o get_nbr_count.o hype_itoa.o initialize_rest.o itoa_base.o parse_variables.o print_char.o print_int.o print_min_width.o print_plus.o print_pointer.o print_string.o print_zeros.o set_values.o print_double.o print_octal.o print_percent.o print_u.o print_hexa.o itoa_base_capital.o input_int.o int_period.o input_double.o

LIB_A = srcs/Libft/libft.a

all: $(NAME)

$(NAME):
	@echo "Making 'o' files..."
	@gcc $(FLAGS) -c $(OBJ) $(HDR)
	@echo "Compiling..."
	@cp $(LIB_A) $(NAME)
	@ar rc $(NAME) $(FILES_O)
	@echo "Done."

clean:
	@echo "Cleaning o_files..."
	@/bin/rm -f $(FILES_O)

fclean: clean
	@echo "Removing libftprintf.a"
	@/bin/rm -f $(NAME)

re: fclean all
