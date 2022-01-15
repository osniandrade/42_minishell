/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:34:57 by ocarlos-          #+#    #+#             */
/*   Updated: 2022/01/15 13:33:00 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int init_path(t_data *d)
{
	int i;

	d->path = ft_split(getenv("PATH"), ':');
	i = 0;
	while(d->path[i] != NULL)
	{
		printf("%s\n", (d->path)[i]);
		i++;
	}
	return 0;
}

static int free_path(t_data *d)
{
	int i;

	i = 0;
	while((d->path)[i] != NULL)
	{
		free((d->path)[i]);
		i++;
	}
	free(d->path);
	return 0;
}


int	main(int argc, char *argv[], char *envp[])
{
	t_data	d;
	int		wstatus;
	int		i;
	
	if (argv[1] == NULL)
		argc = argc - 1;
	init_path(&d);
	signal(SIGINT, SIG_IGN);  // disables ctrl+c
	while (TRUE)
	{
		if ((d.input = readline("$>> ")) != NULL)
		{
			i = ft_strlen(d.input);
			d.input[i] = '\n';
			d.args = calloc((MAXARGS + 1) , sizeof(char *));
			d.ptr = d.input;		

			// ignore empty input
			if (*d.ptr == '\n')
			{
				free(d.input);
				free(d.args);
				continue;
			}
			// convert input line to list of arguments
			i = 0;
			while (i < (int) sizeof(d.args) && *d.ptr)
			{
				if (*d.ptr == ' ')
				{
					d.ptr++;
					continue;
				}					
				if (*d.ptr == '\n')
					break;
				d.args[i++] = d.ptr;
				while (*d.ptr && (*d.ptr != ' ') && (*d.ptr != '\n'))
					d.ptr++;
				if (*d.ptr == '\n')
				{
					*d.ptr = '\0';
					break;
				}					
				*d.ptr = '\0';
				d.ptr++;
			}

			// built-in: exit
			if (ft_strncmp(EXITCMD, d.args[0], ft_strlen(EXITCMD)) == 0)
			{
				free(d.input);
				free(d.args); //?
				free_path(&d); //
				printf("\n%s\n", getenv("PATH"));
				return (0);
			}

			// fork child and execute program
			i = (ft_strlen(d.args[0]) + 6) * sizeof(char);
			d.cmd = malloc(i);
			ft_memcpy(d.cmd, "/bin/\0", (6 * sizeof(char)));
			
			
			ft_strlcat(d.cmd, d.args[0], i);
			signal(SIGINT, SIG_DFL);  // enables ctrl+c
			
			if (fork() == 0)
				exit(execve(d.cmd, d.args, envp)); //exit(execvp(d.args[0], d.args));
			
			signal(SIGINT, SIG_IGN);  // disables ctrl+c

			free(d.cmd);
			free(d.input);
			free(d.args); //?

			// wait for program to finish and print exit status
			wait(&wstatus);
			if (WIFEXITED(wstatus))
				printf("<%d>\n", WEXITSTATUS(wstatus));
		}		
	}	
}