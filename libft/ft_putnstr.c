/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:58:15 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/06 18:06:13 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char *str, size_t start, size_t end)
{
	if (start > end || end >= ft_strlen(str))
		return ;
	while (start <= end && str[start])
	{
		ft_putchar(str[start]);
		start++;
	}
}
