# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:04:53 by pchadeni          #+#    #+#              #
#    Updated: 2017/12/22 14:32:22 by pchadeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
C_FLAGS = -Wall -Wextra -Werror
FILES =  disp_path.c \
		 err.c \
		 tfile.c \
		 isx.c \
		 opt.c \
		 opt_l.c \
		 opt_l2.c \
		 pars.c \
		 print_id.c \
		 print_name.c \
		 print_file.c \
		 sp_colums.c \
		 qs_av.c \
		 qs_path.c \
		 qs_size.c \
		 qs_time.c \
		 qs_taccess.c \
		 qs_tcreat.c \
		 qs_tstatus.c \
		 rec_opt.c \
		 tfile2.c \
		 main.c

OBJ = $(FILES:.c=.o)
NAME = ft_ls


all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft/ MAKEFLAGS=
	@$(CC) $(OBJ) ./libft/libft.a -o $(NAME)
	@echo "\033[01;32mft_ls created √\033[22;0m"

%.o : %.c
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	@$(CC) $(C_FLAGS) -c $<

clean:
	@$(MAKE) clean -C libft/
	@rm -Rf $(OBJ)
	@echo "\033[01;32mft_ls clean √\033[22;0m"

fclean: clean
	@$(MAKE) fclean -C libft/
	@rm -Rf $(NAME)
	@echo "\033[01;32mft_ls fclean √\033[22;0m"

re: fclean all
