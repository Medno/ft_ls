/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 14:24:01 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/06 12:36:34 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*sort_file_rep(t_list **av, t_list **file, uint8_t ptab[])
{
	t_list	*fold;
	t_list	*tmp;
	t_stat	sb;

	tmp = *av;
	fold = NULL;
	while (tmp != NULL)
	{
		lstat(tmp->content, &sb);
		if (isdir(sb) || (islink(sb) && !islong(ptab)))
			ft_lstaddlast(&fold, ft_lstnew(tmp->content, tmp->content_size));
		else
			ft_lstaddlast(file, ft_lstnew(tmp->content, tmp->content_size));
		tmp = tmp->next;
	}
	ft_lstdel(av, ft_lstclean);
	if (!ptab[11])
	{
		(fold) ? qs_av(&fold) : 0;
		(*file) ? qs_av(file) : 0;
	}
	return (fold);
}

void	treat_file(t_list *list, uint8_t ptab[])
{
	t_file	*first;
	t_file	*file;
	t_list	*tmp;

	first = NULL;
	tmp = list;
	while (tmp != NULL)
	{
		disp_path(tmp->content, ptab, &file);
		ft_fileaddlast(&first, file);
		tmp = tmp->next;
	}
	p_file(&first, 0, ptab, 0);
	del_file(&first);
}

void	treat_fold(t_list *list, uint8_t ptab[], uint8_t *ft_bool)
{
	t_list	*tmp;
	t_file	*first;

	first = NULL;
	tmp = list;
	while (tmp != NULL)
	{
		disp_fold(tmp->content, &first, ptab, *ft_bool);
		*ft_bool = 2;
		tmp = tmp->next;
	}
}

void	ft_ls(t_list *av, uint8_t ptab[])
{
	t_list	*fold;
	t_list	*file;
	uint8_t	fbool;

	file = NULL;
	fold = NULL;
	fold = sort_file_rep(&av, &file, ptab);
	(file) ? treat_file(file, ptab) : 0;
	fbool = (file || fold->next != NULL) ? 1 : 0;
	(file && fold) ? ft_putchar('\n') : 0;
	(fold) ? treat_fold(fold, ptab, &fbool) : 0;
	(file) ? ft_lstdel(&file, ft_lstclean) : 0;
	(fold) ? ft_lstdel(&fold, ft_lstclean) : 0;
}
