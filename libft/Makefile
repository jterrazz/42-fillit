# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jterrazz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/12 20:58:37 by jterrazz          #+#    #+#              #
#    Updated: 2017/04/17 15:46:09 by jterrazz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


OFILES = $(FILES:.c=.o)

all : $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(FILES)
	ar rc $(NAME) $(OFILES)
	ranlib $(NAME)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all
