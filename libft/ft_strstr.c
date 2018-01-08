/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:44:05 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/08 10:31:30 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*tmp_hay;
	char	*tmp_needle;

	i = 0;
	j = 0;
	tmp_hay = (char *)haystack;
	tmp_needle = (char *)needle;
	if (*tmp_needle == '\0')
		return (tmp_hay);
	while (tmp_hay[i])
	{
		j = 0;
		if (tmp_hay[i] == tmp_needle[j])
			while (tmp_hay[i + j] == tmp_needle[j] || tmp_needle[j] == '\0')
			{
				if (tmp_needle[j] == '\0')
					return (&tmp_hay[i]);
				j++;
			}
		i++;
	}
	return (NULL);
}
