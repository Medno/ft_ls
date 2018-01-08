/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_colums.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:21:59 by pchadeni          #+#    #+#             */
/*   Updated: 2017/12/08 17:30:15 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fill_tab(t_file **first, uint32_t tab[])
{
	t_file	*lst;

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	lst = *first;
	while (lst != NULL)
	{
		tab[0] = (lst->lenuid > tab[0]) ? lst->lenuid : tab[0];
		tab[1] = (lst->lengrp > tab[1]) ? lst->lengrp : tab[1];
		tab[2] = (lst->tenlink > tab[2]) ? lst->tenlink : tab[2];
		tab[3] = (lst->tensize > tab[3]) ? lst->tensize : tab[3];
		tab[4] += lst->stat.st_blocks;
		lst = lst->next;
	}
}
