/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:34:57 by ocarlos-          #+#    #+#             */
/*   Updated: 2022/01/17 19:10:12 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	d;
	int		wstatus;
	int		i;

	
	
	if (argv[1] == NULL)
		argc = argc - 1;		

	signal(SIGINT, SIG_IGN);  // disables ctrl+c


	// TESTE HASHTABLE
	char	**dirpath;
	//char	*sizeenvpath;
	char	*env;
	char	filepath[256];
	DIR		*dp;
	struct	dirent *dir;
	struct	stat statbuf;
	

	i = 0;
	env = strdup(getenv("PATH"));
	dirpath = ft_split(env, ':');
	while (dirpath != NULL)
	{
		if ((dp = opendir(dirpath[i])) != NULL)
		{
			while ((dir = readdir(dp)))
			{
				if (dir->d_ino != 0)
				{
					strcpy(filepath, dirpath[i]);
					strcat(filepath, "/");
					strcat(filepath, dir->d_name);
					if (lstat(filepath, &statbuf) >= 0)
						if (S_ISREG(statbuf.st_mode))
							if (access(filepath, X_OK) == 0)
								printf("insert %s in hash\n", dir->d_name); //hashinsert(d->d_name, filepath);
				}
			}
			closedir(dp);
		}
		i++;
	}
	
	// FIM TESTE HASHTABLE

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
				free(d.args);
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
			free(d.args);

			// wait for program to finish and print exit status
			wait(&wstatus);
			if (WIFEXITED(wstatus))
				printf("<%d>\n", WEXITSTATUS(wstatus));

		}
	}	
}