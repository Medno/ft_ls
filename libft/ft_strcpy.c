/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:41:00 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/08 19:25:51 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int			i;
	const char	*tmp;

	i = 0;
	tmp = src;
	while (tmp[i])
	{
		dst[i] = tmp[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
