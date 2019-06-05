/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:50:22 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/10 21:13:07 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(tmp->content = (void *)malloc(content_size)))
		return (NULL);
	if (content == 0)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
	}
	else
	{
		tmp->content = ft_strcpy(tmp->content, content);
		tmp->content_size = content_size;
		tmp->next = NULL;
	}
	return (tmp);
}
