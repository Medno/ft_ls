/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:20:37 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/10 20:45:50 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	tmp = NULL;
	if (lst && f)
	{
		tmp = ft_lstnew(lst->content, lst->content_size);
		tmp = (*f)(lst);
		tmp->next = ft_lstmap(lst->next, f);
	}
	return (tmp);
}
