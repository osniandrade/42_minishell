# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 23:47:34 by ocarlos-          #+#    #+#              #
#    Updated: 2022/01/12 21:00:41 by ebresser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = minishell.c \
		helper1.c

OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
ADD_LIBS = -lreadline


all:		$(NAME)

$(NAME):	$(OBJ)
			@gcc $(FLAG) $(SRC) $(ADD_LIBS) -o minishell

debug:
			@gcc $(FLAG) $(DEBUG) $(SRC) $(ADD_LIBS) -o minishell

run:
			./minishell

clean:
			@/bin/rm -f $(OBJ)

fclean:		clean
			@/bin/rm -f $(NAME)

re:			fclean all