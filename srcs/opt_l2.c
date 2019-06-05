/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:15:08 by pchadeni          #+#    #+#             */
/*   Updated: 2019/06/05 10:59:44 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	p_time(time_t t, uint8_t ptab[])
{
	time_t pres;

	pres = time(NULL);
	if (t < pres && pres - t < 15552000 && !ptab[6])
		ft_putsegment(ctime(&t), 4, 15);
	else if (!ptab[6])
	{
		ft_putsegment(ctime(&t), 4, 10);
		ft_putchar(' ');
		ft_putsegment(ctime(&t), 20, 23);
	}
	else
		ft_putsegment(ctime(&t), 4, 23);
}

void	print_time(t_stat stat, uint8_t ptab[])
{
	if (!ptab[19] && !ptab[7] && !ptab[9])
		p_time(stat.st_mtime, ptab);
	else if (ptab[9] && !ptab[7])
		p_time(stat.st_ctime, ptab);
	else if (ptab[7])
		p_time(stat.st_birthtime, ptab);
	else
		p_time(stat.st_atime, ptab);
}

void	print_size(t_file *file, uint32_t tab[])
{
	while (tab[3] - file->tensize > 0)
	{
		if (file->tensize > 0)
			ft_putchar(' ');
		file->tensize++;
	}
	if ((file->stat.st_mode & S_IFMT) == S_IFBLK ||
			(file->stat.st_mode & S_IFMT) == S_IFCHR)
	{
		ft_putnbr(major(file->stat.st_rdev));
		ft_putstr(", ");
		ft_putnbr(minor(file->stat.st_rdev));
	}
	else
		ft_putnbr(file->stat.st_size);
}

void	print_l(char *path)
{
	char	buff[10000];

	ft_bzero(buff, sizeof(buff));
	if (readlink(path, buff, 10000) != -1)
	{
		ft_putstr(" -> ");
		ft_putstr(buff);
	}
}

void	print_all(t_file *file, uint32_t tab[], uint8_t ptab[])
{
	print_type(file->stat);
	print_mode(file->stat);
	put_acl(file, file->path, ptab);
	print_link(file, tab);
	ft_putchar(' ');
	print_id(file, tab, ptab);
	ft_putstr("  ");
	print_size(file, tab);
	ft_putchar(' ');
	print_time(file->stat, ptab);
	ft_putchar(' ');
}
