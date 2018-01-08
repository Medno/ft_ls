/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:37:52 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/08 18:47:45 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	const char	*tmp_s;
	char		*tmp;
	size_t		i;

	i = 0;
	tmp = NULL;
	if (s)
	{
		tmp_s = s;
		if ((tmp = ft_strnew(ft_strlen(tmp_s))))
		{
			while (tmp_s[i])
			{
				tmp[i] = (*f)(i, tmp_s[i]);
				i++;
			}
			tmp[i] = '\0';
		}
	}
	return (tmp);
}
