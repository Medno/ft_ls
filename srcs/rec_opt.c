/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:33:13 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/06 11:15:40 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_file_reverse(t_file **begin_list)
{
	t_file *list;
	t_file *next;
	t_file *prev;

	list = *begin_list;
	prev = 0;
	while (list)
	{
		next = list->next;
		list->next = prev;
		prev = list;
		list = next;
	}
	*begin_list = prev;
}

void	in_fold(t_file *tmp, t_file *nfirst, uint8_t ptab[])
{
	int	i;

	if (isdir(tmp->stat) && !isdot(ft_strrchr(tmp->path, '/') + 1))
	{
		i = disp_fold(tmp->path, &nfirst, ptab, 2);
		if (i > 0 && isdot(ft_strrchr(tmp->path, '/') + 1))
			del_file(&nfirst);
	}
}

void	rec_fold(t_file **first, uint8_t ptab[])
{
	t_file	*tmp;
	t_file	*nfirst;

	nfirst = NULL;
	if (ptab[17] && !ptab[11])
		ft_file_reverse(first);
	tmp = *first;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->path, "/sgoinfre") != 0)
			in_fold(tmp, nfirst, ptab);
		tmp = tmp->next;
	}
	if (nfirst)
		del_file(&nfirst);
}

void	rec_p(t_file *file, uint8_t ptab[], uint32_t tab[], uint8_t i)
{
	if (file->next != NULL)
		rec_p(file->next, ptab, tab, i);
	p_one(file, tab, ptab, i);
}
