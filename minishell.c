/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:34:57 by ocarlos-          #+#    #+#             */
/*   Updated: 2022/01/10 22:50:31 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_data	d;
	int		wstatus;
	int		i;
	
	d.envp = malloc(sizeof(char*) * 2);
	d.ptr = getenv("PATH");
	i = (ft_strlen(d.ptr) + 6) * sizeof(char);
	d.envp[0] = malloc(i);
	ft_memcpy(d.envp[0], "PATH=\0", (6 * sizeof(char)));
	ft_strlcat(d.envp[0], d.ptr, i);
	d.envp[1] = NULL;

	while (TRUE)
	{
		d.input = malloc((PRMTSIZ + 1) * sizeof(char));
		d.args = malloc((MAXARGS + 1) * sizeof(char *));
		ft_memset(d.input, 0, (PRMTSIZ + 1));
		ft_memset(d.args, 0, (MAXARGS + 1));
		d.ptr = d.input;

		// prompt
		printf("$>> ");
		fgets(d.input, PRMTSIZ, stdin);

		// ignore empty input
		if (*d.ptr == '\n')
			continue;
		
		// convert input line to list of arguments
		i = 0;
		while (i < (int) sizeof(d.args) && *d.ptr)
		{
			if (*d.ptr == ' ')
				continue;
			if (*d.ptr == '\n')
				break;
			d.args[i++] = d.ptr;
			while (*d.ptr && (*d.ptr != ' ') && (*d.ptr != '\n'))
				d.ptr++;
			*d.ptr = '\0';
			d.ptr++;
		}

		// built-in: exit
		if (ft_strncmp(EXITCMD, d.args[0], ft_strlen(EXITCMD)) == 0)
		{
			free(d.input);
			free(d.args);
			free(d.envp[0]);
			free(d.envp);
			return (0);
		}
		
		// fork child and execute program
		i = (ft_strlen(d.args[0]) + 10) * sizeof(char);
		d.cmd = malloc(i);
		ft_memcpy(d.cmd, "/usr/bin/\0", (10 * sizeof(char)));
		ft_strlcat(d.cmd, d.args[0], i);
		signal(SIGINT, SIG_DFL);  // enables ctrl+c
		if (fork() == 0)
		{
			exit(execve(d.cmd, d.args, d.envp));
			//exit(execvp(d.args[0], d.args));
		}
		signal(SIGINT, SIG_IGN);  // disables ctrl+c

		free(d.cmd);
		free(d.input);
		free(d.args);

		// wait for program to finish and print exit status
		wait(&wstatus);
		if (WIFEXITED(wstatus))
			printf("<%d>\n", WEXITSTATUS(wstatus));
	}
}