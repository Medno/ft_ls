/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:19:15 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/08 14:05:30 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		tmp[len];
	const char	*tmp_src;
	char		*tmp_dst;
	size_t		i;

	i = 0;
	tmp_dst = dst;
	tmp_src = src;
	if (len > 100000000)
		return (0);
	while (i < len)
	{
		tmp[i] = tmp_src[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		tmp_dst[i] = tmp[i];
		i++;
	}
	return (tmp_dst);
}
