/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuussaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:01:38 by pkuussaa          #+#    #+#             */
/*   Updated: 2019/10/25 14:11:15 by pkuussaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *dst;

	dst = *alst;
	if (alst != NULL && del != NULL)
	{
		while (dst->next)
		{
			dst = *alst;
			*alst = (*alst)->next;
			del(dst->content, dst->content_size);
			free(dst);
		}
		free(*alst);
		*alst = NULL;
	}
}
