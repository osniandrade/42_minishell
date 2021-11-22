/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:16:23 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/11/22 21:20:15 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define TRUE 1
# define FALSE 0
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <string.h>

typedef struct s_cmd
{
	char	cmd[100];
	char	command[100];
	char	*parameters[20];
	char	**envp; // = {(char *) "PATH=/bin", 0};
}			t_cmd;

typedef struct s_count
{
	int		i;
	int		j;
	int		c;
}			t_count;

typedef struct s_read
{
	char	line[1024];
	int		count;
	char	*array[100];
	char	*pch;
}			t_read;

void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strdup(const char *s1);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif