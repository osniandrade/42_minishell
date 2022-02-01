/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:16:23 by ocarlos-          #+#    #+#             */
/*   Updated: 2022/01/20 23:15:05 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <sys/stat.h>

# define TRUE 1
# define FALSE 0
# define MAXARGS 63
# define EXITCMD "exit"

typedef struct s_data
{
	char	*input;
	char	*ptr;
	char	**args;
	char	*cmd;
}			t_data;

typedef struct s_hashlist
{
	struct hashlist	*next;
	char			*command;
	char			*fullpath;
}					t_hashlist;


// helper1.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strcat(char *dst, const char *src);

#endif