/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:48:29 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/10 15:59:32 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstsplit(char const *s, char c)
{
	t_list	*lst;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	lst = NULL;
	if (s && c)
		while (s[i])
		{
			if (s[i] != c && s[i + 1])
			{
				len = 0;
				while (s[i + len] != c && s[i + len])
					len++;
				ft_lstaddlast(&lst, ft_lstnew(ft_strsub(s, i, len), len));
				i += len;
			}
			i = (s[i]) ? i + 1 : i;
			return (lst);
		}
	return (NULL);
}
