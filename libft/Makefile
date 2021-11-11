# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/22 19:09:13 by ocarlos-          #+#    #+#              #
#    Updated: 2020/02/19 19:15:05 by ocarlos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_memcpy.c ft_memset.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memmove.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isprint.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_tolower.c \
		ft_toupper.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_bzero.c ft_calloc.c ft_isascii.c ft_isdigit.c ft_strchr.c \
		ft_strdup.c ft_strnstr.c ft_strrchr.c ft_itoa.c ft_putendl_fd.c \
		ft_split.c ft_strjoin.c ft_substr.c ft_strmapi.c ft_strtrim.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c

OBJ = 	ft_memcpy.o ft_memset.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
		ft_memmove.o ft_atoi.o ft_isalnum.o ft_isalpha.o ft_isprint.o \
		ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_tolower.o \
		ft_toupper.o ft_putchar_fd.o ft_putnbr_fd.o ft_putstr_fd.o \
		ft_bzero.o ft_calloc.o ft_isascii.o ft_isdigit.o ft_strchr.o \
		ft_strdup.o ft_strnstr.o ft_strrchr.o ft_itoa.o ft_putendl_fd.o \
		ft_split.o ft_strjoin.o ft_substr.o ft_strmapi.o ft_strtrim.o

BONUSOBJ = 	ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
			ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o \
			ft_lstmap.o

FLAGS = -Wall -Wextra -Werror

OPTIONS = -c

all : $(NAME)

$(NAME):
	@gcc $(FLAGS) $(OPTIONS) $(SRC) && ar rc $(NAME) $(OBJ)

bonus: 	
	@gcc $(FLAGS) $(OPTIONS) $(SRC) $(BONUS) && ar rc $(NAME) $(OBJ) $(BONUSOBJ)

clean:
	@/bin/rm -f $(OBJ) $(BONUSOBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
