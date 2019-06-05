/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:47:15 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/20 13:51:55 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlchr(const char *s, int c)
{
	char	*tmp;
	char	*res;
	int		i;
	int		max;

	i = 0;
	max = -1;
	tmp = ft_strdup(s);
	while (tmp[i])
	{
		if (tmp[i] == c)
			max = i;
		i++;
	}
	if (tmp[i] == '\0' && c == '\0')
		max = i;
	if (max == -1)
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	tmp[max + 1] = '\0';
	res = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (res);
}
