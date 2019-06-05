/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:12:23 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/29 14:38:40 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

uint8_t	isdir(t_stat sb)
{
	if ((sb.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}

uint8_t	isdot(char *path)
{
	if (ft_strcmp(path, ".") == 0 || ft_strcmp(path, "..") == 0)
		return (1);
	return (0);
}

uint8_t	isexe(t_stat stat)
{
	if (stat.st_mode & S_IXUSR)
		return (1);
	if (stat.st_mode & S_IXGRP)
		return (1);
	if (stat.st_mode & S_IXOTH)
		return (1);
	return (0);
}

uint8_t	islink(t_stat stat)
{
	if ((stat.st_mode & S_IFMT) == S_IFLNK)
		return (1);
	return (0);
}

uint8_t	islong(uint8_t ptab[])
{
	if (ptab[13] || ptab[15] || ptab[12])
		return (1);
	return (0);
}
