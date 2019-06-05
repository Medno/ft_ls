/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:33:35 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/29 14:44:40 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_uid(t_file *file, uint32_t tab[])
{
	t_passwd	*pass;

	pass = getpwuid(file->stat.st_uid);
	if (pass)
		ft_putstr(pass->pw_name);
	else
		ft_putnbr(file->stat.st_uid);
	while (tab[0] - file->lenuid > 0)
	{
		ft_putchar(' ');
		file->lenuid++;
	}
}

void	print_gid(t_file *file, uint32_t tab[])
{
	t_grp		*grp;

	grp = getgrgid(file->stat.st_gid);
	if (grp)
		ft_putstr(grp->gr_name);
	else
		ft_putnbr(file->stat.st_gid);
	while (tab[1] - file->lengrp > 0)
	{
		ft_putchar(' ');
		file->lengrp++;
	}
}

void	print_id(t_file *file, uint32_t tab[], uint8_t ptab[])
{
	if (!ptab[12])
		print_uid(file, tab);
	if (!ptab[15])
	{
		if (!ptab[12])
			ft_putstr("  ");
		print_gid(file, tab);
	}
}
