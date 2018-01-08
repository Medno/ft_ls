/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsgap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 10:48:31 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/21 15:22:01 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsgap(char *str, char n, int i)
{
	int	count;
	int	start;
	int	end;

	count = 0;
	start = 0;
	end = 0;
	while (str[end] != '\0')
	{
		if (str[end] == n)
		{
			count++;
			if (count >= i && str[end - 1])
			{
				ft_putnstr(str, start, end - 1);
				return ;
			}
			if (str[end + 1])
				start = end + 1;
		}
		end++;
	}
	ft_putnstr(str, start, end - 1);
}
