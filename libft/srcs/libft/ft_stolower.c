/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stolower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:54:30 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/20 12:08:38 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stolower(char *str)
{
	int		i;
	char	*tmp;

	i = ft_strlen(str);
	tmp = ft_strnew(i);
	while (i >= 0)
	{
		tmp[i] = ft_tolower(str[i]);
		i--;
	}
	return (tmp);
}
