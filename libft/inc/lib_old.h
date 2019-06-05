/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:10:25 by pchadeni          #+#    #+#             */
/*   Updated: 2019/06/05 12:53:49 by pchadeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_OLD
# define LIBFT_OLD

# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char			*ft_onejoinf(char *news, char *old);
char			*ft_strjoinfree(char *s1, char *s2);

void			ft_putsegment(char *str, size_t start, size_t end);

#endif
