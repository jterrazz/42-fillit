# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 14:21:01 by jterrazz          #+#    #+#              #
#    Updated: 2017/04/20 17:27:44 by jterrazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_PATH = ./src

LIB_PATH = ./libft

SRC_NAME = fillit.c printer.c reader.c checker.c error.c resolver.c \
		   create_map.c get_pieces.c optimize_pieces.c

LIB_NAME = ft_lstiter.c ft_putendl.c ft_striter.c ft_strequ.c\
	ft_lstmap.c ft_putendl_fd.c ft_striteri.c ft_strrchr.c \
	ft_atoi.c ft_lstnew.c ft_putnbr.c ft_strjoin.c ft_strsplit.c \
	ft_bzero.c ft_memalloc.c ft_putnbr_fd.c ft_strlcat.c ft_strstr.c \
	ft_isalnum.c ft_memccpy.c ft_putstr.c ft_strlen.c ft_strsub.c \
	ft_isalpha.c ft_memchr.c ft_putstr_fd.c ft_strmap.c ft_strtrim.c \
	ft_isascii.c ft_memcmp.c ft_strcat.c ft_strmapi.c ft_tolower.c \
	ft_isdigit.c ft_memcpy.c ft_strchr.c ft_strncat.c ft_toupper.c \
	ft_isprint.c ft_memdel.c ft_strclr.c ft_strncmp.c \
	ft_itoa.c ft_memmove.c ft_strcmp.c ft_strncpy.c \
	ft_lstadd.c ft_memset.c ft_strcpy.c ft_strnequ.c \
	ft_lstdel.c ft_putchar.c ft_strdel.c ft_strnew.c \
	ft_lstdelone.c ft_putchar_fd.c ft_strdup.c ft_strnstr.c ft_sqrt.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))

OFILES = $(SRC_NAME:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	@make -C libft/ all
	@$(CC) $(CFLAGS) -o $(NAME) $(OFILES) ./libft/libft.a
	@echo "Compilation:\033[92m OK\033[0m"

%.o: $(SRC_PATH)/%.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	@make -C libft/ clean
	@rm -rf $(OFILES)
	@echo "Deleting:\n\033[33m $(OFILES)\033[0m"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "Deleting:\n\033[33m $(NAME)\033[0m"

re : fclean all

.PHONY: all clean fclean re
