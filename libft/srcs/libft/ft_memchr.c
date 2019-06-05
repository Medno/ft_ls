/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:07:47 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/10 10:32:50 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)tmp[i] == (unsigned char)c)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
