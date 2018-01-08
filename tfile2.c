/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfile2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:55:28 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/06 11:12:36 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	size_file(t_file *first)
{
	t_file	*tmp;
	size_t	res;

	res = 0;
	tmp = first;
	while (tmp != NULL)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}

void	print_f_line(t_file *file, size_t s[], uint32_t tab[], uint8_t ptab[])
{
	size_t	tmp;
	size_t	len;

	while (s[6] < s[0] && s[5] + s[6] * s[1] < s[3] && file)
	{
		len = (s[8] == 1) ?
			ft_strlen(ft_strrchr(file->path, '/') + 1) : ft_strlen(file->path);
		tmp = 0;
		s[7] = (s[2] / 8) + 1;
		p_one(file, tab, ptab, s[8]);
		while (s[7] - (s[9] + len) / 8 > 0 && s[5] + (s[6] + 1) * s[1] < s[3])
		{
			ft_putchar('\t');
			s[7]--;
		}
		s[6]++;
		while (tmp < s[1] && file)
		{
			file = file->next;
			tmp++;
		}
	}
}

void	print_f(t_file *first, size_t s[], uint32_t tab[], uint8_t ptab[])
{
	t_file	*file;
	t_file	*nfirst;

	s[5] = 0;
	nfirst = first;
	while (s[5] < s[1])
	{
		file = nfirst;
		s[6] = 0;
		if (s[5] + s[6] * s[1] < s[3] && s[6] < s[0])
		{
			print_f_line(file, s, tab, ptab);
			ft_putchar('\n');
		}
		s[5]++;
		nfirst = nfirst->next;
	}
}

void	fill_s(t_file *first, uint8_t i, uint8_t ptab[], size_t s[])
{
	t_file	*tmp;

	tmp = first;
	s[0] = 1;
	s[2] = 0;
	s[4] = 0;
	s[3] = size_file(tmp);
	s[8] = i;
	s[9] = (ptab[2] || ptab[16]) ? 1 : 0;
	while (s[4] < s[3])
	{
		if (s[8] == 1)
			s[2] = (s[2] < s[9] + ft_strlen((ft_strrchr(tmp->path, '/') + 1)))
				? ft_strlen((ft_strrchr(tmp->path, '/') + 1)) + s[9] : s[2];
		else
			s[2] = (s[2] < s[9] + ft_strlen(tmp->path)) ?
				ft_strlen(tmp->path) + s[9] : s[2];
		s[4]++;
		tmp = tmp->next;
	}
}

void	p_col(t_file *first, uint8_t i, uint32_t tab[], uint8_t ptab[])
{
	size_t			s[10];
	struct winsize	win;

	fill_s(first, i, ptab, s);
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	s[4] = 0;
	while (s[4] < s[2])
		s[4] += 8;
	s[4] = (s[4] - s[2] != 0) ? s[4] - s[2] : 8;
	while (s[0] * (s[2] + s[4]) <= win.ws_col)
		s[0]++;
	s[0]--;
	s[1] = s[3] / s[0];
	if (s[1] * s[0] < s[3] - 1)
		s[1]++;
	if (s[1] == 0)
		s[1]++;
	print_f(first, s, tab, ptab);
}
