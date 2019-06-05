/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:14:29 by pchadeni          #+#    #+#             */
/*   Updated: 2018/01/06 12:34:43 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	analyse_rep(DIR *rep, char *str, uint8_t ptab[], t_file **first)
{
	t_file	*file;
	t_dir	*read;
	int		j;

	file = NULL;
	while ((read = readdir(rep)))
	{
		if (!ptab[8] && !ptab[11])
			while ((read->d_name[0] == '.' && !ptab[1])
					|| isdot(read->d_name))
				if (!(read = readdir(rep)))
					return (1);
		file = new_tfile();
		if (!(file->path = ft_strdup(str)))
			return (0);
		if (ft_strcmp(str, "/") != 0)
			file->path = ft_strjoinfree(file->path, "/");
		file->path = ft_strjoinfree(file->path, read->d_name);
		j = fill_tfile(file);
		(j > 0) ? ft_fileaddlast(first, file) : del_file(&file);
	}
	if (read == NULL && errno == EBADF)
		errls(str, 2);
	return (1);
}

int	read_folder(t_file **file, char *newpath, char *str)
{
	DIR		*rep;
	t_dir	*read;

	rep = opendir(newpath);
	if (rep)
	{
		newpath = ft_strjoinfree(newpath, str);
		while ((read = readdir(rep)))
			if (ft_strcmp(read->d_name, ft_strrchr(newpath, '/') + 1) == 0)
			{
				*file = new_tfile();
				(*file)->path = ft_strdup(str);
				fill_tfile(*file);
				ft_strdel(&newpath);
				return ((closedir(rep) != -1) ? 1 : 0);
			}
		if (read == NULL)
		{
			ft_strdel(&newpath);
			closedir(rep);
			return (0);
		}
	}
	ft_strdel(&newpath);
	return (1);
}

int	disp_path(char *str, uint8_t ptab[], t_file **file)
{
	DIR			*rep;
	char		*newpath;
	t_stat		sb;

	rep = NULL;
	if (lstat(str, &sb) == -1)
		return (0);
	if (!islink(sb) && (rep = opendir(str)))
	{
		if (analyse_rep(rep, str, ptab, file) && closedir(rep) != -1)
			return (1);
		return (0);
	}
	else if (islink(sb) && !ptab[13] && (rep = opendir(str)))
	{
		if (analyse_rep(rep, str, ptab, file) && closedir(rep) != -1)
			return (1);
		return (0);
	}
	else if (rep == NULL && errno == EACCES)
		return (-1);
	newpath = ft_strlchr(str, '/');
	newpath = (newpath == NULL) ? ft_strdup("./") : newpath;
	return (read_folder(file, newpath, str));
}

int	disp_fold(char *av, t_file **first, uint8_t ptab[], uint8_t bl)
{
	t_file	*file;
	int		err;

	file = NULL;
	if (bl > 0)
	{
		(bl == 2) ? ft_putchar('\n') : 0;
		ft_putstr(av);
		ft_putstr(":\n");
	}
	err = disp_path(av, ptab, &file);
	if (err > 0)
	{
		ft_fileaddlast(first, file);
		p_file(first, 1, ptab, 1);
		if (*first && ptab[4])
			rec_fold(first, ptab);
		if (*first)
			del_file(first);
		return (1);
	}
	return ((err < 0) ? errls(av, 2) : 0);
}
