/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:22:52 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/02 15:29:14 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_ext(t_file *file)
{
	if (isdir(file->stat))
		ft_putchar('/');
	else if (islink(file->stat))
		ft_putchar('@');
	else if ((file->stat.st_mode & S_IFMT) == S_IFIFO)
		ft_putchar('|');
	else if ((file->stat.st_mode & S_IFMT) == S_IFSOCK)
		ft_putchar('=');
	else if ((file->stat.st_mode & S_IFMT) == S_IFWHT)
		ft_putchar('%');
	else if (isexe(file->stat))
		ft_putchar('*');
}

void	print_keys(t_file *file)
{
	char	s[1024];
	int		j;
	int		len;

	j = 0;
	ft_bzero(s, sizeof(s));
	if ((len = listxattr(file->path, s, 1024, XATTR_NOFOLLOW)) > 0)
	{
		while (j < len)
		{
			write(1, "\t", 1);
			ft_putstr(&s[j]);
			write(1, "\t", 1);
			ft_putnbr(getxattr(file->path, &s[j], NULL, 0, 0, XATTR_NOFOLLOW));
			write(1, "\n", 1);
			j += ft_strlen(s) + 1;
		}
	}
}

void	param_fold(char *tmp)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(tmp, ',');
	while (tab[i])
	{
		if (!(ft_strcmp(tab[i], "deny") == 0))
		{
			if (ft_strcmp(tab[i], "read") == 0)
				ft_putstr("list");
			else if (ft_strcmp(tab[i], "write") == 0)
				ft_putstr("add_file");
			else if (ft_strcmp(tab[i], "execute") == 0)
				ft_putstr("search");
			else if (ft_strcmp(tab[i], "append") == 0)
				ft_putstr("add_subdirectory");
			else
				ft_putstr(tab[i]);
			(tab[i + 1]) ? write(1, ",", 1) : ft_putchar('\0');
		}
		ft_strdel(&tab[i++]);
	}
	free(tab);
}

void	last_param(char *tmp, t_file *file)
{
	char	*last;
	int		i;

	i = 1;
	if (!(last = ft_strstr(tmp, "allow")))
		if (!(last = ft_strstr(tmp, "deny")))
			return ;
	while (*last != ',' && *last != ':')
		last++;
	if (isdir(file->stat))
		param_fold(ft_strrchr(&tmp[i], ':') + 1);
	else
	{
		if (ft_strrchr(tmp, ':'))
			ft_putstr(ft_strrchr(tmp, ':') + 1);
	}
	if (*last == ',' && !ft_strstr(last, ",inherit"))
	{
		write(1, ",", 1);
		ft_putsgap(&last[i], ':', 1);
	}
	write(1, "\n", 1);
}

void	print_acl(t_file *file)
{
	char	**tmp;
	int		i;

	i = 1;
	tmp = ft_strsplit(file->acl, '\n');
	ft_strdel(&tmp[0]);
	while (tmp[i])
	{
		ft_putchar(' ');
		ft_putnbr(i - 1);
		ft_putstr(": ");
		ft_putsgap(tmp[i], ':', 1);
		write(1, ":", 1);
		ft_putsgap(tmp[i], ':', 3);
		write(1, " ", 1);
		(ft_strstr(tmp[i], ",inherit")) ? ft_putstr("inherit ") : 0;
		if (ft_strstr(tmp[i], "allow"))
			ft_putstr("allow ");
		else if (ft_strstr(tmp[i], "deny"))
			ft_putstr("deny ");
		last_param(tmp[i], file);
		ft_strdel(&tmp[i]);
		i++;
	}
	free(tmp);
}
