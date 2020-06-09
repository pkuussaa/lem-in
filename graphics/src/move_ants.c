/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <pkuussaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:43:16 by pkuussaa          #+#    #+#             */
/*   Updated: 2020/06/09 18:05:19 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/graphics.h"

int		get_ant(char *str)
{
	return (ft_atoi(ft_strsplit(str + 1, '-')[0]));
}

char	*get_room_name(char *str)
{
	return (ft_strsplit(str, '-')[1]);
}

t_ants	*find_ant(t_ants **ants, int name)
{
	int		i;

	i = 0;
	while (ants[i])
	{
		if (ants[i]->name == name)
			return (ants[i]);
		i++;
	}
	return (NULL);
}

char	**initialize_char_array(char *str, char *str2)
{
	char	**arr;

	if (!(arr = (char**)malloc(sizeof(char*) * 3)))
		exit(EXIT_FAILURE);
	arr[0] = ft_strdup(str);
	arr[1] = ft_strdup(str2);
	arr[2] = NULL;
	return (arr);
}

int		move_ants(t_graphics *info, t_ants **ants)
{
	int			i;
	int			y;
	int			count;
	double		**arr;

	y = 0;
	if (!info->result[y])
		return (-1);

	while (info->result[y])
	{
		count = 0;
		i = 0;
		while (info->result[y][count])
			count++;
		if (!(arr = (double**)malloc(sizeof(double*) * count)))
			exit(EXIT_FAILURE);
		while (info->result[y][i])
		{
			arr[i] = get_draw_coordinates(handle_link(info->room, initialize_char_array(find_ant(ants,
			get_ant(info->result[y][i]))->room_name, get_room_name(info->result[y][i])))); //ottaa antin roomin ja sen suraavan roomin lahto coordinaatit
			find_ant(ants, get_ant(info->result[y][i]))->room_name = get_room_name(info->result[y][i]);
			ft_printf("result: %s\n", info->result[y][i]); // POISTA
			i++;
		}
		info->ant_moves[y] = arr;
		y++;
	}
	/*for (int j = 0;j < count;j++) // POISTA
	{
		for (int k = 0;k < 4;k++)
			ft_printf("%f\n", arr[j][k]);
	}*/
	return (0);
}
