/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:15:52 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/02 15:07:50 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*new_tfile(void)
{
	t_file	*tmp;

	if (!(tmp = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	tmp->path = NULL;
	tmp->acl = NULL;
	tmp->tenlink = 0;
	tmp->tensize = 0;
	tmp->lenuid = 0;
	tmp->lengrp = 0;
	tmp->uid = NULL;
	tmp->grp = NULL;
	tmp->next = NULL;
	return (tmp);
}

int		fill_tfile(t_file *file)
{
	if (lstat(file->path, &file->stat) != -1)
	{
		if ((file->uid = getpwuid(file->stat.st_uid)))
			file->lenuid = (uint8_t)ft_strlen(file->uid->pw_name);
		else
			file->lenuid = ft_expten(file->stat.st_uid);
		if ((file->grp = getgrgid(file->stat.st_gid)))
			file->lengrp = (uint8_t)ft_strlen(file->grp->gr_name);
		else
			file->lengrp = ft_expten(file->stat.st_gid);
		file->tenlink = ft_expten(file->stat.st_nlink);
		file->tensize = ft_expten(file->stat.st_size);
		return (1);
	}
	return (errls(file->path, 3));
}

void	ft_fileaddlast(t_file **list, t_file *add)
{
	t_file	*begin;

	if (!(*list))
		(*list) = add;
	else
	{
		begin = *list;
		while (begin->next)
			begin = begin->next;
		begin->next = add;
	}
}

void	del_file(t_file **first)
{
	if ((*first)->next == NULL)
	{
		ft_strdel(&(*first)->path);
		ft_strdel(&(*first)->acl);
		free(*first);
		*first = NULL;
	}
	else
	{
		del_file(&(*first)->next);
		ft_strdel(&(*first)->path);
		ft_strdel(&(*first)->acl);
		free(*first);
		*first = NULL;
	}
}

t_file	*gettail(t_file *file)
{
	while (file != NULL && file->next != NULL)
		file = file->next;
	return (file);
}
