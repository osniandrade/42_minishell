# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 23:47:34 by ocarlos-          #+#    #+#              #
#    Updated: 2022/01/15 13:03:27 by ebresser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = minishell.c 

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
HEADERS = -I ./includes

LIBFT_DIR = ./libft
ADD_LIBS = -lreadline -L $(LIBFT_DIR) -lft

RM = /bin/rm -f

all:		$(NAME)

$(NAME):	$(OBJS) make_libft
			$(CC) $(FLAGS) $(HEADERS) $(OBJS) $(ADD_LIBS) -o $@

debug:		$(OBJS) make_libft
			$(CC) $(FLAGS) $(HEADERS) $(DEBUG) $(OBJS) $(ADD_LIBS) -o $(NAME)

%.o:	%.c    
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@

make_libft:
	make -C $(LIBFT_DIR)

run:
			./minishell

clean:
			@make clean -C $(LIBFT_DIR)
			@$(RM) $(OBJS)

fclean:		clean
			@make fclean -C $(LIBFT_DIR)
			@$(RM) $(NAME)

re:			fclean all