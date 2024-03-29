# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 14:57:58 by pchadeni          #+#    #+#              #
#    Updated: 2019/06/05 10:38:27 by pchadeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------Name of the project------#

NAME = ft_ls

#------All sources------#

MAIN_SRCS = disp_path.c \
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

OBJ += $(addprefix ./$(OBJ_PATH)/, $(MAIN_SRCS:.c=.o))

#------Includes------#

INCLUDES = ./inc/
INC += -I $(INCLUDES)
INC += -I $(LIB_PATH)/$(INCLUDES)
LIB = $(LIB_PATH)/libft.a

HEAD = $(INCLUDES)/ft_ls.h

#------Path------#

SRCS_PATH = srcs
OBJ_PATH  = obj
LIB_PATH  = libft

#------Main rules------#

all: $(OBJ_PATH) makelib $(NAME)

$(NAME): $(LIB) $(OBJ) $(OBJ_NM) $(OBJ_OTOOL)
	@printf "\33[2KObjects created $(BOLD_GREEN)✓$(EOC)\n"
	@printf "Start making $(NAME)...\n"
	@$(CC) $(C_FLAGS) $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIB)
	@printf "$(BOLD_GREEN)⤖     $(NAME)$(EOC) created $(BOLD_GREEN)✓$(EOC)\n"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@printf "$(OBJ_PATH) created\n"

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c $(HEAD)
	@$(CC) $(FLAGS) $(C_FLAGS) $(INC) -o $@ -c $<
	@printf " $(COL_GREEN)[OK]$(EOC) $(COL_YELLOW)Compiling:$(EOC) $<\r"

makelib:
	@make -C $(LIB_PATH) NOERR=$(NOERR) DEV=$(DEV) SAN=$(SAN)

clean: cleanlib
	@rm -Rf $(OBJ_PATH)
	@rm -Rf $(TEST_OBJ)
	@echo "$(BOLD_GREEN)$(NAME)$(EOC) clean $(BOLD_GREEN)✓$(EOC)"

cleanlib:
	@make clean -C $(LIB_PATH)

fclean: fcleanlib clean
	@rm -Rf $(NAME)
	@echo "$(BOLD_GREEN)$(NAME)$(EOC) fclean $(BOLD_GREEN)✓$(EOC)"

fcleanlib:
	@make fclean -C $(LIB_PATH)

re: fclean all

#------Compilation's flags------#

CC = gcc

# flags
C_FLAGS = -Wall -Wextra

ifneq ($(NOERR),yes)
	C_FLAGS += -Werror
endif

ifeq ($(DEV),yes)
	FLAGS += -g
endif

ifeq ($(SAN),yes)
	FLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

#------Define colors------#

BOLD_GREEN = \033[01;32m
COL_GREEN = \033[0;32m
COL_YELLOW = \033[0;33m
EOC = \033[0m

.PHONY: all re fclean clean
