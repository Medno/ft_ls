/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:02:33 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/07 10:14:22 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*tmp;

	if (s1 && s2)
	{
		if ((tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			tmp = ft_strcat(tmp, s1);
			tmp = ft_strcat(tmp, s2);
			ft_strdel(&s1);
			return (tmp);
		}
	}
	return (NULL);
}
