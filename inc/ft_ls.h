/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:02:57 by pchadeni          #+#    #+#             */
/*   Updated: 2019/06/05 11:03:36 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <grp.h>
# include <sys/ioctl.h>
# include <pwd.h>
# include <inttypes.h>
# include <stdlib.h>
# include <sys/acl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <time.h>
# include <uuid/uuid.h>
# include <errno.h>
# define BIRTH_NSEC st_birthtimespec.tv_nsec

typedef struct stat		t_stat;
typedef struct dirent	t_dir;
typedef struct passwd	t_passwd;
typedef struct group	t_grp;

typedef struct			s_file
{
	t_stat			stat;
	char			*path;
	char			*acl;
	t_passwd		*uid;
	t_grp			*grp;
	uint8_t			lenuid;
	uint8_t			lengrp;
	uint8_t			tenlink;
	uint8_t			tensize;
	struct s_file	*next;
}						t_file;

int						errls(char *str, uint8_t i);
int						usage(char valid[], char *param, int j);
void					check_valid(int ac, char **av, int i);
void					not_file(t_list **del, uint8_t tab[]);

t_file					*new_tfile(void);
t_file					*gettail(t_file *cur);
void					del_file(t_file **file);
void					ft_fileaddlast(t_file **list, t_file *add);

void					ft_file_reverse(t_file **begin_list);

uint8_t					isdir(t_stat sb);
uint8_t					isdot(char *path);
uint8_t					isexe(t_stat stat);
uint8_t					islink(t_stat stat);
uint8_t					islong(uint8_t ptab[]);

void					print_acl(t_file *file);
void					print_all(t_file *f, uint32_t tab[], uint8_t ptab[]);
void					print_ext(t_file *file);
void					p_file(t_file **fi, uint8_t i, uint8_t p[], uint8_t fo);
void					print_id(t_file *file, uint32_t tab[], uint8_t ptab[]);
void					print_keys(t_file *file);
void					print_l(char *path);
void					print_link(t_file *file, uint32_t tab[]);
void					print_mode(t_stat stat);
void					print_name(t_file *file, uint8_t ptab[], uint8_t i);
void					p_one(t_file *f, uint32_t t[], uint8_t p[], uint8_t i);
void					put_acl(t_file *file, char *path, uint8_t ptab[]);
void					print_time(t_stat stat, uint8_t ptab[]);
void					p_tot(uint32_t tab[]);
void					print_type(t_stat stat);
void					print_size(t_file *file, uint32_t tab[]);

int						analyse_rep(DIR *r, char *s, uint8_t p[], t_file **f);
void					fill_tab(t_file **first, uint32_t tab[]);
int						fill_tfile(t_file *file);
int						disp_fold(char *a, t_file **f, uint8_t p[], uint8_t b);
int						disp_path(char *str, uint8_t ptab[], t_file **file);
void					ft_ls(t_list *av, uint8_t ptab[]);

void					rec_fold(t_file **first, uint8_t ptab[]);
void					rec_p(t_file *f, uint8_t p[], uint32_t t[], uint8_t i);

void					qs_argv(char **tab, int debut, int fin);
void					qs_fold(char **tab, int debut, int fin);
void					qs_av(t_list **first);
void					qs_path(t_file **first);
void					qs_size(t_file **first);
void					qs_time(t_file **first);
void					qs_taccess(t_file **first);
void					qs_tcreat(t_file **first);
void					qs_tstatus(t_file **first);

size_t					size_file(t_file *first);
void					p_col(t_file *f, uint8_t i, uint32_t t[], uint8_t p[]);
#endif
