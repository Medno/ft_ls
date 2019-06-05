/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:33:45 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/06 11:55:44 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	p_one(t_file *file, uint32_t tab[], uint8_t ptab[], uint8_t i)
{
	if (islong(ptab) && !ptab[14] && !ptab[21])
		print_all(file, tab, ptab);
	print_name(file, ptab, i);
	if (ptab[2])
		print_ext(file);
	else if (ptab[16])
		if (isdir(file->stat))
			ft_putchar('/');
	if (islong(ptab) && islink(file->stat) && !ptab[14] && !ptab[21])
		print_l(file->path);
	(ptab[21]) ? 0 : ft_putchar('\n');
	if (ptab[0] && islong(ptab) && !ptab[21])
		print_keys(file);
	if (ptab[10] && islong(ptab) && file->acl != NULL && !ptab[21])
		print_acl(file);
}

void	qs_all(t_file **file, uint8_t ptab[])
{
	if (!ptab[5] && !ptab[18] && !ptab[11])
		qs_path(file);
	else if (ptab[5] && !ptab[11])
		qs_size(file);
	else if (ptab[18] && !ptab[11])
	{
		if (ptab[7])
			qs_tcreat(file);
		else if (ptab[19])
			qs_taccess(file);
		else if (ptab[9])
			qs_tstatus(file);
		else
			qs_time(file);
	}
}

void	print_m(t_file **first, t_file *file, uint8_t i, uint8_t ptab[])
{
	if (ptab[17])
	{
		if (file->next != NULL)
			print_m(first, file->next, i, ptab);
		print_name(file, ptab, i);
		if (file == *first)
			ft_putstr("\n");
		else if (file == *first && file->next == NULL)
			ft_putchar('\n');
		else
			ft_putstr(", ");
	}
	else
	{
		print_name(file, ptab, i);
		if (file->next != NULL)
		{
			ft_putstr(", ");
			print_m(first, file->next, i, ptab);
		}
		else
			ft_putchar('\n');
	}
}

void	one_line(t_file *list, uint32_t tab[], uint8_t ptab[], uint8_t i)
{
	if (!ptab[17] || ptab[11])
	{
		while (list != NULL)
		{
			p_one(list, tab, ptab, i);
			list = list->next;
		}
	}
	else
		rec_p(list, ptab, tab, i);
}

void	p_file(t_file **file, uint8_t i, uint8_t ptab[], uint8_t fold)
{
	t_file		*list;
	uint32_t	tab[5];

	if (!*file)
		return ;
	qs_all(file, ptab);
	fill_tab(file, tab);
	list = *file;
	(islong(ptab) && fold && list != NULL && !ptab[14] && !ptab[21]) ?
		p_tot(tab) : 0;
	if (!ptab[14])
	{
		if (!ptab[21])
			one_line(list, tab, ptab, i);
		else
		{
			(ptab[17]) ? ft_file_reverse(file) : 0;
			p_col(*file, i, tab, ptab);
		}
	}
	else
		print_m(file, list, i, ptab);
}
