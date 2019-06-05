/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:50:39 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/10 11:01:01 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		len;

	i = 0;
	if (size == 0)
		return (ft_strlen(dst));
	while (dst[i] && i < size)
		i++;
	len = i;
	while (src[i - len] && size - 1 > i)
	{
		dst[i] = src[i - len];
		i++;
	}
	while (i < size)
	{
		dst[i] = '\0';
		i++;
	}
	return (len + ft_strlen(src));
}
