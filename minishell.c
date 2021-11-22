/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:34:57 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/11/18 00:05:20 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** reads the command and directs it to the bin folder
*/

void	read_command(char cmd[], char *par[])
{
	t_read	rc;
	t_count	c;

	rc = (t_read){0};
	c = (t_count){0};
	while (TRUE)
	{
		c.c = fgetc(stdin);
		rc.line[rc.count++] = (char) c.c;
		if (c.c == '\n')
			break;
	}
	if (rc.count == 1)
		return;
	rc.pch = strtok(rc.line, " \n");
	while (rc.pch != NULL)
	{
		rc.array[c.i++] = ft_strdup(rc.pch);
		rc.pch = strtok(NULL, " \n");
	}
	ft_strlcpy(cmd, rc.array[0], 100);
	while(c.j < c.i)
	{ 
		par[c.j] = rc.array[c.j];
		c.j++;
	}
	par[c.i] = NULL;
}

/*
** formats the terminal and prints the '#' symbol
** in each iteraction
*/

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
	t_cmd	cmd;

	cmd.envp[0] = (char *) "PATH=/bin";
	cmd.envp[1] = NULL;
	while (TRUE)
	{
		type_prompt();
		read_command(cmd.command, cmd.parameters);
		if (fork() != FALSE)
			wait (NULL);
		else
		{
			ft_strlcpy(cmd.cmd, "/bin/", 6);
			ft_strlcat(cmd.cmd, cmd.command, 100);  // adjust size to actual present values
			execve(cmd.cmd, cmd.parameters, cmd.envp) ;
		}
		if (ft_strncmp(cmd.command, "exit", 5) == 0)
			break;
	}
	return (0);
}