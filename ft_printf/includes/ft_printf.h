/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:09:38 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/01/21 17:40:05 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../srcs/Libft/libft.h"

typedef	struct	s_lst
{
	const char	*format;
	char		*copy;
	va_list		args;
	int			len;
	size_t		i;
	long int	period;
	long int	field_width;
	int			negative;
	int			zeros_printed;
	int			is_dot;
	char		arg_type;
	char		flag_arr[6];
	char		modifier_arr[3];
	char		*arguments;
	char		*flags;
	char		*modifiers;
}				t_lst;

int				ft_printf(const char *format, ...);
int				parse_variables(t_lst *arr);
int				get_nbr_count(intmax_t len);

char			*hype_itoa(intmax_t n);
char			*itoa_base(uintmax_t i, int base);
char			*itoa_base_capital(uintmax_t i, int base);

t_lst			*print_char(t_lst *arr);
t_lst			*set_values(t_lst *arr);
t_lst			*initialize_rest(t_lst *arr);
t_lst			*check_width(t_lst *arr);
t_lst			*check_flags(t_lst *arr);
t_lst			*check_period(t_lst *arr);
t_lst			*check_modifier_type(t_lst *arr);
t_lst			*choose_printed_arg(t_lst *arr);
t_lst			*check_arg_type(t_lst *arr);
t_lst			*print_min_width(t_lst *arr, int length, intmax_t i);
t_lst			*print_int(t_lst *arr);
t_lst			*print_zeros(t_lst *arr, int length, intmax_t i);
t_lst			*print_plus(t_lst *arr, intmax_t i);
t_lst			*print_string(t_lst *arr);
t_lst			*print_pointer(t_lst *arr);
t_lst			*print_double(t_lst *arr);
t_lst			*input_int(t_lst *arr, intmax_t i);
t_lst			*print_octal(t_lst *arr);
t_lst			*print_percent(t_lst *arr);
t_lst			*print_u(t_lst *arr);
t_lst			*print_hexa(t_lst *arr);
t_lst			*input_int(t_lst *arr, intmax_t i);
t_lst			*period(t_lst *arr, intmax_t i);
t_lst			*input_double(t_lst *arr, long double i);

#endif
