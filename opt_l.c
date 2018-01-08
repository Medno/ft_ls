/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:57:19 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/06 12:20:36 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	p_tot(uint32_t tab[])
{
	ft_putstr("total ");
	ft_putnbr(tab[4]);
	ft_putchar('\n');
}

void	print_type(t_stat stat)
{
	if (stat.st_mode & S_IFMT)
	{
		if ((stat.st_mode & S_IFMT) == S_IFIFO)
			ft_putchar('p');
		else if ((stat.st_mode & S_IFMT) == S_IFCHR)
			ft_putchar('c');
		else if ((stat.st_mode & S_IFMT) == S_IFDIR)
			ft_putchar('d');
		else if ((stat.st_mode & S_IFMT) == S_IFBLK)
			ft_putchar('b');
		else if ((stat.st_mode & S_IFMT) == S_IFLNK)
			ft_putchar('l');
		else if ((stat.st_mode & S_IFMT) == S_IFSOCK)
			ft_putchar('s');
		else if ((stat.st_mode & S_IFMT) == S_IFWHT)
			ft_putchar('w');
		else if ((stat.st_mode & S_IFMT) == S_IFREG)
			ft_putchar('-');
	}
}

void	put_acl(t_file *file, char *path, uint8_t ptab[])
{
	acl_t			acl;
	acl_entry_t		dummy;

	acl = NULL;
	dummy = NULL;
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putstr("@ ");
	else if (acl != NULL)
		ft_putstr("+ ");
	else
		ft_putstr("  ");
	if (acl)
	{
		if (ptab[10])
			file->acl = acl_to_text(acl, NULL);
		acl_free((void *)acl);
		acl = NULL;
	}
}

void	print_mode(t_stat stat)
{
	(stat.st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(stat.st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	if (stat.st_mode & S_IXUSR)
		(stat.st_mode & S_ISUID) ? ft_putchar('s') : ft_putchar('x');
	else
		(stat.st_mode & S_ISUID) ? ft_putchar('S') : ft_putchar('-');
	(stat.st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(stat.st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	if (stat.st_mode & S_IXGRP)
		(stat.st_mode & S_ISGID) ? ft_putchar('s') : ft_putchar('x');
	else
		(stat.st_mode & S_ISGID) ? ft_putchar('S') : ft_putchar('-');
	(stat.st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(stat.st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	if (stat.st_mode & S_IXOTH)
		(stat.st_mode & S_ISVTX) ? ft_putchar('t') : ft_putchar('x');
	else
		(stat.st_mode & S_ISVTX) ? ft_putchar('T') : ft_putchar('-');
}

void	print_link(t_file *file, uint32_t tab[])
{
	while (tab[2] - file->tenlink > 0)
	{
		ft_putchar(' ');
		file->tenlink++;
	}
	ft_putnbr(file->stat.st_nlink);
}
