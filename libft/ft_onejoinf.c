/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onejoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 12:09:23 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/11 12:11:35 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_onejoinf(char *news, char *old)
{
	char	*tmp;
	int		i;
	int		j;

	if (news && old && (tmp = ft_strnew(ft_strlen(news) + ft_strlen(old))))
	{
		i = 0;
		j = ft_strlen(news);
		tmp = ft_strcat(tmp, news);
		while (old[i])
		{
			if (!ft_strchr(tmp, old[i]))
			{
				tmp[j] = old[i];
				j++;
			}
			i++;
		}
		tmp[j] = '\0';
		ft_strdel(&news);
		news = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (news);
	}
	return (NULL);
}
