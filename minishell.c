/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:34:57 by ocarlos-          #+#    #+#             */
/*   Updated: 2022/01/04 13:12:48 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;
	char	*ptr;
	char	**args;
	int		wstatus;
	int		i;
	
	while (TRUE)
	{
		input = malloc((PRMTSIZ + 1) * sizeof(char));
		args = malloc((MAXARGS + 1) * sizeof(char *));
		memset(input, 0, (PRMTSIZ + 1));
		memset(args, 0, (MAXARGS + 1));
		ptr = input;

		// prompt
		printf("%s ", getuid() == 0 ? "#" : "$");
		fgets(input, PRMTSIZ, stdin);

		// ignore empty input
		if (*ptr == '\n')
			continue;
		
		// convert input line to list of arguments
		i = 0;
		while (i < (int) sizeof(args) && *ptr)
		{
			if (*ptr == ' ')
				continue;
			if (*ptr == '\n')
				break;
			for (args[i++] = ptr; *ptr && *ptr != ' ' && *ptr != '\n'; ptr++);
			*ptr = '\0';
			ptr++;
		}

		// built-in: exit
		if (strcmp(EXITCMD, args[0]) == 0)
		{
			free(input);
			free(args);
			return (0);
		}
		
		// fork child and execute program
		signal(SIGINT, SIG_DFL);
		if (fork() == 0)
			exit(execvp(args[0], args));
		signal(SIGINT, SIG_IGN);

		free(input);
		free(args);

		// wait for program to finish and print exit status
		wait(&wstatus);
		if (WIFEXITED(wstatus))
			printf("<%d>\n", WEXITSTATUS(wstatus));
		
		
	}
}