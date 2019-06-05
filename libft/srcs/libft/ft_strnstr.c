/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:09:19 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/10 09:58:40 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	n++;
	while (haystack[i] && n)
	{
		j = 0;
		if (haystack[i] == needle[j])
			while ((haystack[i + j] == needle[j] || needle[j] == '\0') && n)
			{
				if (needle[j] == '\0')
					return ((char *)&haystack[i]);
				j++;
				n--;
			}
		n = n + j - 1;
		i++;
	}
	return (NULL);
}
