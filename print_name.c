/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:29:44 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/29 14:30:50 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_fold(t_file *file, char *str)
{
	if ((file->stat.st_mode & S_ISVTX) && (file->stat.st_mode & S_IWOTH))
		ft_putformat(str, BLACK, BG_GREEN);
	else if ((file->stat.st_mode & S_IWOTH))
		ft_putformat(str, BLACK, BG_YELLOW);
	else
		ft_putcolor(str, BLUE);
}

void	print_exe(t_file *file, char *str)
{
	if (file->stat.st_mode & S_ISUID)
	{
		if (file->stat.st_mode & S_IXGRP || file->stat.st_mode & S_IXOTH)
			ft_putformat(str, BLACK, BG_RED);
	}
	else if (file->stat.st_mode & S_ISGID)
	{
		if (file->stat.st_mode & S_IXUSR || file->stat.st_mode & S_IXOTH)
			ft_putformat(str, BLACK, BG_CYAN);
	}
	else
		ft_putcolor(str, RED);
}

void	print_color(t_file *file, char *str)
{
	if ((file->stat.st_mode & S_IFMT) == S_IFBLK)
		ft_putformat(str, BLUE, BG_CYAN);
	else if ((file->stat.st_mode & S_IFMT) == S_IFCHR)
		ft_putformat(str, BLUE, BG_YELLOW);
	else if ((file->stat.st_mode & S_IFMT) == S_IFSOCK)
		ft_putcolor(str, GREEN);
	else if (islink(file->stat))
		ft_putcolor(str, MAGENTA);
	else if ((file->stat.st_mode & S_IFMT) == S_IFIFO)
		ft_putcolor(str, YELLOW);
	else if (isexe(file->stat))
		print_exe(file, str);
	else
		ft_putstr(str);
}

void	print_name(t_file *file, uint8_t ptab[], uint8_t i)
{
	if (i == 1 && ptab[3])
	{
		if (isdir(file->stat))
			print_fold(file, ft_strrchr(file->path, '/') + 1);
		else
			print_color(file, ft_strrchr(file->path, '/') + 1);
	}
	else if (i == 1)
		ft_putstr(ft_strrchr(file->path, '/') + 1);
	else if (ptab[3])
	{
		if (isdir(file->stat))
			print_fold(file, file->path);
		else
			print_color(file, file->path);
	}
	else
		ft_putstr(file->path);
}
