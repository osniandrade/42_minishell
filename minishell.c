/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:34:57 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/11/12 00:08:34 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	read_command(char cmd[], char *par[])
{
	char	line[1024];
	int		count;
	int		i;
	int		j;
	char	*array[100];
	char	*pch;

	count = 0;
	i = 0;
	j = 0;
	while (TRUE)
	{
		int c = fgetc(stdin);
		line[count++] = (char) c;
		if (c == '\n')
			break;
	}
	if (count == 1)
		return;
	pch = strtok(line, " \n");
	while (pch != NULL)
	{
		array[i++] = ft_strdup(pch);
		pch = strtok(NULL, " \n");
	}
	ft_strlcpy(cmd, array[0], 100);
	while(j < i)
	{ 
		par[j] = array[j];
		j++;
	}
	par[i] = NULL;
}

void	type_prompt(void)
{
	static int	first_time;
	const char	*CLEAR_SCREEN_ANSI;

	first_time = 0;
	if (first_time)
	{
		CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";
		write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
		first_time = 0;
	}
	printf("#");
}

int main(void)
{
	char cmd[100];
	char command[100];
	char *parameters[20];
	char *envp[] = {(char *) "PATH=/bin", 0};

	while (TRUE)
	{
		type_prompt();
		read_command(command, parameters);
		if (fork() != FALSE)
			wait (NULL);
		else
		{
			ft_strlcpy(cmd, "/bin/", 6);
			ft_strlcat(cmd, command, 100);  // adjust size to actual present values
			execve(cmd, parameters, envp) ;
		}
		if (ft_strncmp(command, "exit", 5) == 0)
			break;
	}
	return (0);
}