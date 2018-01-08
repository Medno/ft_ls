# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:04:53 by pchadeni          #+#    #+#              #
#    Updated: 2018/01/06 11:05:43 by pchadeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
C_FLAGS = -Wall -Wextra -Werror
FILES = ft_atoi.c \
		ft_abs.c \
		ft_bzero.c \
		ft_expten.c \
		ft_foreachint.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_iswhitesp.c \
		ft_itoa.c \
		ft_lstadd.c \
		ft_lstaddlast.c \
		ft_lstclean.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsplit.c \
		ft_lsttail.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_onejoinf.c \
		ft_pow.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_putnstr.c \
		ft_putsgap.c \
		ft_putcolor.c \
		ft_putformat.c \
		ft_sqrt.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strjoinfree.c \
		ft_strlcat.c \
		ft_strlchr.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_stolower.c \
		ft_tolower.c \
		ft_toupper.c

OBJ = $(FILES:.c=.o)
NAME = libft.a


all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[01;32mLibft compiled √\033[22;0m"

%.o : %.c
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	@$(CC) $(C_FLAGS) -c $< -I libft.h

clean:
	@rm -Rf $(OBJ)
	@echo "\033[01;32mLibft clean √\033[22;0m"

fclean: clean
	@rm -Rf $(NAME)
	@echo "\033[01;32mLibft fclean √\033[22;0m"

re: fclean all
