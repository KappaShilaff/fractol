# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcassaun <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 17:33:09 by lcassaun          #+#    #+#              #
#    Updated: 2020/06/30 21:21:46 by lcassaun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror 

NAME = libft.a

HEADERS_DIR = includes/

HEADERS_LIST = libft.h

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRCS_DIR = srcs/

OBJ_DIR = obj/

INCLUDES = -I$(HEADERS_DIR)

SRCS_LIST = ft_memalloc.c\
			ft_putnbr.c\
			ft_striter.c\
			ft_strnstr.c\
			ft_memccpy.c\
			ft_putnbr_fd.c\
			ft_striteri.c\
			ft_strrchr.c\
			ft_memchr.c\
			ft_putstr.c\
			ft_strjoin.c\
			ft_strsplit.c\
			ft_memcmp.c\
			ft_putstr_fd.c\
			ft_strlcat.c\
			ft_strstr.c\
			ft_atoi.c\
			ft_memcpy.c\
			ft_strcat.c\
			ft_strlen.c\
			ft_strsub.c\
			ft_bzero.c\
			ft_memdel.c\
			ft_strchr.c\
			ft_strmap.c\
			ft_strtrim.c\
			ft_isalnum.c\
			ft_memmove.c\
			ft_strclr.c\
			ft_strmapi.c\
			ft_tolower.c\
			ft_isalpha.c\
			ft_memset.c\
			ft_strcmp.c\
			ft_strncat.c\
			ft_toupper.c\
			ft_isascii.c\
			ft_putchar.c\
			ft_strcpy.c\
			ft_strncmp.c\
			ft_isdigit.c\
			ft_putchar_fd.c\
			ft_strdel.c\
			ft_strncpy.c\
			ft_isprint.c\
			ft_putendl.c\
			ft_strdup.c\
			ft_strnequ.c\
			ft_itoa.c\
			ft_putendl_fd.c\
			ft_strequ.c\
			ft_strnew.c\
			ft_lstnew.c\
			ft_lstdel.c\
			ft_lstdelone.c\
			ft_lstadd.c\
			ft_lstmap.c\
			ft_lstiter.c\
			ft_min.c\
			ft_max.c\
			ft_swap.c\
			ft_isblank.c\
			ft_abs.c\
			ft_lsthead.c\
			ft_lsttale.c\
			ft_lstfree.c\
			ft_findchr.c\
			ft_chmalloc_zend.c\
			ft_putnbr_z_fd.c\
			ft_strlen_z_nb.c\
			ft_strlen_ll_nb.c\
			ft_itoa_base.c\
			ft_unsigned_itoa_base.c\
			ft_chsum.c\
			ft_chmult.c\
			ft_chexp.c\
			ft_chround.c\
			get_next_line.c\
			ft_memstrncpy.c\
			ft_free_enull.c\
			ft_create_cont_fd.c\
			ft_create_node.c\
			ft_abs_f.c\


SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJ_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all:  $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean 
	@rm -rf $(NAME)

re: fclean all
