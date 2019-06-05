/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:44:30 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/06 12:46:48 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*sort_av(int ac, char **av, int i, uint8_t tab[])
{
	t_list	*fdel;
	t_list	*res;
	t_stat	sb;

	fdel = NULL;
	res = NULL;
	while (i < ac)
	{
		if (stat(av[i], &sb) == 0)
			ft_lstaddlast(&res, ft_lstnew(av[i], ft_strlen(av[i])));
		else
			ft_lstaddlast(&fdel, ft_lstnew(av[i], ft_strlen(av[i])));
		i++;
	}
	if (fdel != NULL)
		not_file(&fdel, tab);
	return (res);
}

void	fill_tparam(char *p, uint8_t tab[])
{
	tab[0] = ft_strchr(p, '@') ? 1 : 0;
	tab[1] = ft_strchr(p, 'A') ? 1 : 0;
	tab[2] = ft_strchr(p, 'F') ? 1 : 0;
	tab[3] = ft_strchr(p, 'G') ? 1 : 0;
	tab[4] = ft_strchr(p, 'R') ? 1 : 0;
	tab[5] = ft_strchr(p, 'S') ? 1 : 0;
	tab[6] = ft_strchr(p, 'T') ? 1 : 0;
	tab[7] = ft_strchr(p, 'U') ? 1 : 0;
	tab[8] = ft_strchr(p, 'a') ? 1 : 0;
	tab[9] = ft_strchr(p, 'c') ? 1 : 0;
	tab[10] = ft_strchr(p, 'e') ? 1 : 0;
	tab[11] = ft_strchr(p, 'f') ? 1 : 0;
	tab[12] = ft_strchr(p, 'g') ? 1 : 0;
	tab[13] = ft_strchr(p, 'l') ? 1 : 0;
	tab[14] = ft_strchr(p, 'm') ? 1 : 0;
	tab[15] = ft_strchr(p, 'o') ? 1 : 0;
	tab[16] = ft_strchr(p, 'p') ? 1 : 0;
	tab[17] = ft_strchr(p, 'r') ? 1 : 0;
	tab[18] = ft_strchr(p, 't') ? 1 : 0;
	tab[19] = ft_strchr(p, 'u') ? 1 : 0;
	tab[20] = ft_strchr(p, '1') ? 1 : 0;
	tab[21] = ft_strchr(p, 'C') ? 1 : 0;
}

int		check_param(int argc, char **argv, int *i, uint8_t tab[])
{
	char	*param;
	int		j;
	char	valid[23];

	j = 0;
	ft_strcpy(valid, "@ACFGRSTUacefglmoprtu1");
	if (!(param = ft_strdup("")))
		return (0);
	while (*i < argc && argv[*i][0] == '-' && ft_strlen(argv[*i]) != 1)
	{
		param = ft_onejoinf(param, &argv[*i][1]);
		(*i)++;
		if (*i < argc && ft_strcmp(argv[*i], "--") == 0)
			if ((*i)++)
				break ;
	}
	while (param[j] != '\0')
	{
		if (!ft_strchr(valid, param[j]))
			return (usage(valid, param, j));
		j++;
	}
	fill_tparam(param, tab);
	ft_strdel(&param);
	return (1);
}

int		main(int argc, char **argv)
{
	uint8_t	tparam[22];
	t_list	*av;
	t_file	*file;
	int		i;

	i = 1;
	file = NULL;
	if (check_param(argc, argv, &i, tparam) > 0)
	{
		check_valid(argc, argv, i);
		if (i == argc)
		{
			disp_path(".", tparam, &file);
			p_file(&file, 1, tparam, 1);
			if (tparam[4])
				rec_fold(&file, tparam);
		}
		else
		{
			if ((av = sort_av(argc, argv, i, tparam)))
				ft_ls(av, tparam);
		}
	}
	return (0);
}
