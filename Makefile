# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 23:47:34 by ocarlos-          #+#    #+#              #
#    Updated: 2022/01/04 13:24:23 by ocarlos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = minishell.c \
		helper1.c

OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address

all:		$(NAME)

$(NAME):	$(OBJ)
			@gcc $(FLAG) $(SRC) -o minishell

debug:
			@gcc $(FLAG) $(DEBUG) $(SRC) -o minishell

run:
			./minishell

clean:
			@/bin/rm -f $(OBJ)

fclean:		clean
			@/bin/rm -f $(NAME)

re:			fclean all