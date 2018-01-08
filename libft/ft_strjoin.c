/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:56:28 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/09 09:15:37 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (s1 && s2)
	{
		if ((tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			tmp = ft_strcat(tmp, s1);
			tmp = ft_strcat(tmp, s2);
			return (tmp);
		}
	}
	return (NULL);
}
