/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:48:40 by pchadeni          #+#    #+#             */
/*   Updated: 2017/11/08 19:00:36 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	const char	*tmp_s1;
	const char	*tmp_s2;

	tmp_s1 = s1;
	tmp_s2 = s2;
	if (s1 && s2)
	{
		if (!ft_strcmp(tmp_s1, tmp_s2))
			return (1);
	}
	return (0);
}
