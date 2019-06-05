/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:05:14 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/02 15:19:19 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		aux(t_list **prev, t_list **cur, t_list **tail)
{
	t_list	*tmp;

	if (*prev)
		(*prev)->next = (*cur)->next;
	tmp = (*cur)->next;
	(*cur)->next = NULL;
	(*tail)->next = *cur;
	(*tail) = *cur;
	*cur = tmp;
}

static t_list	*part(t_list *head, t_list *end, t_list **nhead, t_list **nend)
{
	t_list	*pivot;
	t_list	*prev;
	t_list	*cur;
	t_list	*tail;

	pivot = end;
	prev = NULL;
	cur = head;
	tail = pivot;
	while (cur != pivot)
	{
		if (ft_strcmp(cur->content, pivot->content) < 0)
		{
			if ((*nhead) == NULL)
				(*nhead) = cur;
			prev = cur;
			cur = cur->next;
		}
		else
			aux(&prev, &cur, &tail);
	}
	if ((*nhead) == NULL)
		(*nhead) = pivot;
	(*nend) = tail;
	return (pivot);
}

static t_list	*quicksortrecur(t_list *head, t_list *end)
{
	t_list	*newhead;
	t_list	*newend;
	t_list	*pivot;
	t_list	*tmp;

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
		tmp = ft_lsttail(newhead);
		tmp->next = pivot;
	}
	pivot->next = quicksortrecur(pivot->next, newend);
	return (newhead);
}

void			qs_av(t_list **headref)
{
	(*headref) = quicksortrecur(*headref, ft_lsttail(*headref));
	return ;
}
