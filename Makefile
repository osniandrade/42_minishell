# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 23:47:34 by ocarlos-          #+#    #+#              #
#    Updated: 2021/11/11 23:55:14 by ocarlos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = minishell.c \
		ft_strdup.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strncmp.c \
		ft_strlen.c \
		ft_memcpy.c

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