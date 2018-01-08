/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:22:14 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/10 10:35:52 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*tmp_s1;
	char	*tmp_s2;

	tmp_s1 = (char *)s1;
	tmp_s2 = (char *)s2;
	if (!n)
		return (0);
	while ((*tmp_s1 && *tmp_s2) && *tmp_s1 == *tmp_s2 && n - 1 > 0)
	{
		tmp_s1++;
		tmp_s2++;
		n--;
	}
	return ((unsigned char)*tmp_s1 - (unsigned char)*tmp_s2);
}
