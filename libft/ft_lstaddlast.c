/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:14:44 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/12 16:54:35 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list **list, t_list *add)
{
	t_list	*begin;

	if (!(*list))
		(*list) = add;
	else
	{
		begin = *list;
		while (begin->next)
			begin = begin->next;
		begin->next = add;
	}
}
