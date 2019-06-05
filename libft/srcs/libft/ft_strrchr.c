/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:15:48 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/08 10:07:43 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;
	int		max;

	i = 0;
	max = -1;
	tmp = (char *)s;
	while (tmp[i])
	{
		if (tmp[i] == c)
			max = i;
		i++;
	}
	if (tmp[i] == '\0' && c == '\0')
		max = i;
	if (max == -1)
		return (NULL);
	return (tmp + max);
}
