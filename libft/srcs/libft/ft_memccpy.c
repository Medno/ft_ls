/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:33:40 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/08 13:52:45 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*tmp_dst;
	const char	*tmp_src;
	size_t		i;

	i = 0;
	tmp_dst = dst;
	tmp_src = src;
	while (n > i)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_src[i] == c)
			return (&tmp_dst[i + 1]);
		i++;
	}
	return (NULL);
}
