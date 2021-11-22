# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 23:47:34 by ocarlos-          #+#    #+#              #
#    Updated: 2021/11/17 23:24:54 by ocarlos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = minishell.c \
		helper1.c \
		helper2.c

OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			@gcc $(FLAG) $(SRC) -o minishell

clean:
			@/bin/rm -f $(OBJ)

fclean:		clean
			@/bin/rm -f $(NAME)

re:			fclean all