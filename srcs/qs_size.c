/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:05:14 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/21 16:29:14 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		aux(t_file **prev, t_file **cur, t_file **tail)
{
	t_file	*tmp;

	if (*prev)
		(*prev)->next = (*cur)->next;
	tmp = (*cur)->next;
	(*cur)->next = NULL;
	(*tail)->next = *cur;
	(*tail) = *cur;
	*cur = tmp;
}

static t_file	*part(t_file *h, t_file *end, t_file **nhead, t_file **nend)
{
	t_file	*pivot;
	t_file	*prev;
	t_file	*cur;
	t_file	*tail;

	pivot = end;
	prev = NULL;
	cur = h;
	tail = pivot;
	while (cur != pivot)
	{
		if (cur->stat.st_size > pivot->stat.st_size ||
				(cur->stat.st_size == pivot->stat.st_size &&
				ft_strcmp(cur->path, pivot->path) < 0))
		{
			((*nhead) == NULL) ? (*nhead) = cur : 0;
			prev = cur;
			cur = cur->next;
		}
		else
			aux(&prev, &cur, &tail);
	}
	((*nhead) == NULL) ? (*nhead) = pivot : 0;
	(*nend) = tail;
	return (pivot);
}

static t_file	*quicksortrecur(t_file *head, t_file *end)
{
	t_file	*newhead;
	t_file	*newend;
	t_file	*pivot;
	t_file	*tmp;

	newhead = NULL;
	newend = NULL;
	if (!head || head == end)
		return (head);
	pivot = part(head, end, &newhead, &newend);
	if (newhead != pivot)
	{
		tmp = newhead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;
		newhead = quicksortrecur(newhead, tmp);
		tmp = gettail(newhead);
		tmp->next = pivot;
	}
	pivot->next = quicksortrecur(pivot->next, newend);
	return (newhead);
}

void			qs_size(t_file **headref)
{
	(*headref) = quicksortrecur(*headref, gettail(*headref));
	return ;
}
