/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:24:21 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/06 11:06:42 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		errls(char *str, uint8_t i)
{
	ft_putstr_fd("ls: ", 2);
	if (ft_strrchr(str, '/'))
		ft_putstr_fd(ft_strrchr(str, '/') + 1, 2);
	else
		ft_putstr_fd(str, 2);
	if (i == 1)
		ft_putendl_fd(": No such file or directory", 2);
	if (i == 2)
		ft_putendl_fd(": Permission denied", 2);
	if (i == 3)
		ft_putendl_fd(": Operation not permitted", 2);
	return (0);
}

void	check_valid(int ac, char **av, int i)
{
	while (i < ac)
	{
		if (ft_strcmp(av[i], "") == 0)
		{
			errls("fts_open", 1);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}

void	not_file(t_list **del, uint8_t tab[])
{
	t_list	*tmp;

	if (!tab[11])
		qs_av(del);
	tmp = *del;
	while (tmp != NULL)
	{
		errls(tmp->content, 1);
		tmp = tmp->next;
	}
	ft_lstdel(del, ft_lstclean);
}

int		usage(char valid[], char *param, int j)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(param[j]);
	ft_putstr("\nusage: ls [-");
	ft_putstr(valid);
	ft_putendl("] [file ...]");
	ft_strdel(&param);
	return (0);
}
