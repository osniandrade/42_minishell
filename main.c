/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:34:57 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/11/11 22:51:25 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "libft/libft.h"

int main(void)
{
	char cmd[100];
	char command[100];
	char *parameters[20];
	char *envp[] = {(char *) "PATH=/bin", 0};

	while (1)
	{
		type_prompt();
		read_command(command, parameters);
		if (fork() != 0)
			wait (NULL);
		else
		{
			ft_strcpy(cmd, "/bin/");
			ft_strcat(cmd, command);
			execve(cmd, parameters, envp) ;
		}
		if (ft_strcmp(command, "exit") == 0)
			break;
	}
	return (0);
}