/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:34:57 by ocarlos-          #+#    #+#             */
/*   Updated: 2022/01/10 13:38:50 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;
	char	*ptr;
	char	**args;
	//char	**envp;
	//char	*envp[] = {"PATH=/bin\0", NULL};
	int		wstatus;
	int		i;
	
	
	//envp = malloc(sizeof(char*) * 2);
	// teste
	// ptr = getenv("PATH");
	// int totalsize = (ft_strlen(ptr) + 6) * sizeof(char);
	// envp[0] = malloc(totalsize);
	// ft_memcpy(envp[0], "PATH=\0", (6 * sizeof(char)));
	// ft_strlcat(envp[0], ptr, totalsize);
	// fim teste

	//envp[0] = getenv("PATH");
	//envp[1] = NULL;
	while (TRUE)
	{
		input = malloc((PRMTSIZ + 1) * sizeof(char));
		args = malloc((MAXARGS + 1) * sizeof(char *));
		ft_memset(input, 0, (PRMTSIZ + 1));
		ft_memset(args, 0, (MAXARGS + 1));
		ptr = input;

		// prompt
		printf("$>> ");
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
			args[i++] = ptr;
			while (*ptr && (*ptr != ' ') && (*ptr != '\n'))
				ptr++;
			*ptr = '\0';
			ptr++;
		}

		// built-in: exit
		if (ft_strncmp(EXITCMD, args[0], ft_strlen(EXITCMD)) == 0)
		{
			free(input);
			free(args);
			
			// teste
			//free(envp[0]);
			// fim teste

			//free(envp);
			return (0);
		}
		
		// fork child and execute program
		signal(SIGINT, SIG_DFL);
		if (fork() == 0)
		{
			//exit(execve(args[0], args, envp));
			exit(execvp(args[0], args));
		}
		signal(SIGINT, SIG_IGN);

		free(input);
		free(args);

		// wait for program to finish and print exit status
		wait(&wstatus);
		if (WIFEXITED(wstatus))
			printf("<%d>\n", WEXITSTATUS(wstatus));
	}
}