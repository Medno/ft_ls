/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:05:14 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/20 13:10:49 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	aux(t_file **prev, t_file **cur, t_file **tail)
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

t_file	*partition(t_file *head, t_file *end, t_file **newhead, t_file **newend)
{
	t_file	*pivot;
	t_file	*prev;
	t_file	*cur;
	t_file	*tail;

	pivot = end;
	prev = NULL;
	cur = head;
	tail = pivot;
	while (cur != pivot)
	{
		if (ft_strcmp(cur->path, pivot->path) < 0)
		{
			if ((*newhead) == NULL)
				(*newhead) = cur;
			prev = cur;
			cur = cur->next;
		}
		else
			aux(&prev, &cur, &tail);
	}
	if ((*newhead) == NULL)
		(*newhead) = pivot;
	(*newend) = tail;
	return (pivot);
}

t_file	*quicksortrecur(t_file *head, t_file *end)
{
	t_file	*newhead;
	t_file	*newend;
	t_file	*pivot;
	t_file	*tmp;

	newhead = NULL;
	newend = NULL;
	if (!head || head == end)
		return (head);
	pivot = partition(head, end, &newhead, &newend);
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

void	qs_path(t_file **headref)
{
	(*headref) = quicksortrecur(*headref, gettail(*headref));
	return ;
}
