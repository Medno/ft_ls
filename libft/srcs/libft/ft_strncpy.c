/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:49:08 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/08 19:26:32 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	const char	*tmp;
	size_t		i;
	size_t		temp;

	i = 0;
	tmp = src;
	temp = len;
	while (tmp[i] && temp > i)
	{
		dst[i] = tmp[i];
		i++;
	}
	if (i != len)
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	return (dst);
}
