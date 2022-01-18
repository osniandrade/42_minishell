/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebresser <ebresser@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:34:57 by ocarlos-          #+#    #+#             */
/*   Updated: 2022/01/18 19:47:08 by ebresser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int is_builtin(char *command)
{ //implementar
	int i =	ft_strlen(command);
	i++;
	return 0;
}

static void builtins(t_data *d)
{ //implementar
	int i =	ft_strlen(d->ptr);
	i++;
	return ;
}

static int init_path(t_data *d)
{
	int i;

	d->path = ft_split(getenv("PATH"), ':');
	i = 0;
	while(d->path[i] != NULL)
	{
		ft_strlcat(d->path[i], "/", ft_strlen(d->path[i]) + 2);
		printf("%s\n", (d->path)[i]);//p teste
		i++;
	}
	return 0;
}

/*
static void    ft_execve(t_data *d)
{
    int        i;
    char    *path_aux;

    i = 0;
    while (d->path[i])
    {
        path_aux = ft_strjoin(d->path[i], d->args[0]);
        execve(path_aux, d->args, d->envp);
        i++;
    }
    printf("%s: command not found\n", d->args[0]);
} */

/*static int	find_path(t_data *d)
{
	int	i;

	if (d->cmd)
		free(d->cmd);

	if ((d->path)[d->finder] == NULL)
	{
		d->finder = 0; //voltando agulha p começo
		return -1; //fim de path, n há mais busca
	}
	else
	{
		i = (ft_strlen((d->args)[0]) + ft_strlen((d->path)[d->finder])) * sizeof(char);
		d->cmd = malloc(i); //tratar?
		ft_memcpy(d->cmd, (d->path)[d->finder], (ft_strlen((d->path)[d->finder]) * sizeof(char)));
		ft_strlcat(d->cmd, (d->args)[0], i);
		
		d->finder++;		
	}
	return 0;
}*/
/*static void    ft_execve(t_data *d)
{
    int		i;
    char	*aux;

    i = 0;
    while (d->path[i])
    {
        aux = ft_strjoin(d->path[i], d->args[0]);
        execve(aux, d->args, mini->env.env);
        i++;
    }
    printf("%s: command not found\n", mini->line_read);
}*/

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
	pid_t	chlpid;
	
	if (argv[1] == NULL)
		argc = argc - 1;
	init_path(&d);	
	d.path_aux = NULL;
	//signal(SIGINT, SIG_IGN);  // disables ctrl+c
	while (TRUE)
	{
		if ((d.input = readline("$>> ")) != NULL)
		{
			if (d.path_aux)
				free(d.path_aux);
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
			if (ft_strncmp(EXITCMD, d.args[0], ft_strlen(EXITCMD)) == 0) //alterar exit2323
			{
				free(d.input);
				free(d.args); //?
				free_path(&d); //
				if (d.path_aux)
					free(d.path_aux);
				//printf("\n%s\n", getenv("PATH"));//teste
				return (0);
			}

			//fork child and execute program
			//i = (ft_strlen(d.args[0]) + 6) * sizeof(char);
			//d.cmd = malloc(i);
			//ft_memcpy(d.cmd, "/bin/\0", (6 * sizeof(char)));
			
			
			//ft_strlcat(d.cmd, d.args[0], i);
			//                                     ----------------------------tirei
			//signal(SIGINT, SIG_DFL);  // enables ctrl+c

			//if (fork() == 0)                      VOLTAR
			//	exit(execve(d.cmd, d.args, envp));			
				


			//BUILT IN? ------------------------------------------------
			if (is_builtin(d.args[0])) ///////////////////
				builtins(&d); ///////////////////nao precisa forkar, faz direto
			else
			{
				chlpid = fork();
				if (chlpid == 0) //filho
				{
					//ft_execve(&d); ///////////////////N built-in
					i = 0;
    				while (d.path[i])
    				{
        				d.path_aux = ft_strjoin(d.path[i], d.args[0]);
        				if (execve(d.path_aux, d.args, envp) == -1)
						{
							if (d.path_aux)
								free(d.path_aux);
        					i++;
						}
    				}
    				printf("%s: command not found\n", d.args[0]);
					kill(getpid(), SIGKILL); //n pode usargetpid!
				}
				else
					wait(&wstatus);
					//waitpid(chlpid, &wstatus, WUNTRACED);
										
			}	
			//-------------------------------------------------------		
			
			signal(SIGINT, SIG_IGN);  // disables ctrl+c

			//free(d.cmd);
			free(d.input);
			free(d.args); //?
			if (d.path_aux)
				free(d.path_aux);

			// wait for program to finish and print exit status
			//wait(&wstatus);
			//if (WIFEXITED(wstatus))
			//	printf("<%d>\n", WEXITSTATUS(wstatus));
		}		
	}	
}