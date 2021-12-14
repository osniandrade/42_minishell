#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAXCOM 1000  // max number of letters to be supported
#define MAXLIST 100  // max number of commands to be supported
#define clear() printf("\033[H\033[J")

void	init_shell(void)
{
	clear();
	printf("\n\n\n\n********************"
		"************************");
	printf("\n\n\n\t*********MY SHELL*********");
	printf("\n\n\t - USE AT YOUR OWN RISK -");
	printf("\n\n\n\n********************"
		"************************");
	char *username = getenv("USER");
	printf("\n\n\nUSER is: @%s", username);
	printf("\n");
	sleep(1);
	clear();
}

void	printDir(void)
{
	char	cwd[1024];
	getcwd(cwd, sizeof(cwd));
	printf("\nDir: %s", cwd);
}

int		takeInput(char *str)
{
	char	*buf;

	buf = readline("\n>>> ");
	if (strlen(buf) != 0)
	{
		add_history(buf);
		strcpy(str, buf);
		return (0);
	}
	else
	{
		return (1);
	}
}

int		parsePipe(char *str, char **strpiped)
{
	int		i;
	for (i = 0; i < 2; i++)
	{
		strpiped[i] = strsep(&str, "|");
		if (strpiped[i] == NULL)
			break;
	}
}

void	parseSpace(char *str, char **parsed)
{
	int		i;

	for (i = 0; i < MAXLIST; i++) 
	{
		parsed[i] = strsep(&str, " ");
		if (parsed[i] == NULL)
			break;
		if (strlen(parsed[i]) == 0)
			i--;
	}
}

void	openHelp(void)
{
	puts("\n***WELCOME TO MY SHELL HELP***"
		"\nCopyright @ Junor"
		"\n-Use the shell ar your own risk"
		"\nList of commands supported:"
		"\n>cd"
		"\n>ls"
		"\n>exit"
		"\n>all commands available in UNIX shell"
		"\n>pipe handling"
		"\n>improper space handling");
	return;
}

int		ownCmdHandler(char **parsed)
{
	int		NoOfOwnCmds = 4;
	int		i;
	int		switchOwnArg = 0;
	char	*ListOfOwnCmds[NoOfOwnCmds];
	char	*username;

	ListOfOwnCmds[0] = "exit";
	ListOfOwnCmds[1] = "cd";
	ListOfOwnCmds[2] = "help";
	ListOfOwnCmds[3] = "hello";
	for (i = 0; i < NoOfOwnCmds; i++)
	{
		if (strcmp(parsed[0], ListOfOwnCmds[i]) == 0)
		{
			switchOwnArg = i + 1;
			break;
		}
	}
	switch (switchOwnArg)
	{
		case 1:
			printf("\nGoodbye\n");
			exit(0);
		case 2:
			chdir(parsed[1]);
			return (1);
		case 3:
			openHelp();
			return 1;
		case 4:
			username = getenv("USER)");
			printf("\nHello %s.\nMind that it is "
				"not a place to play around."
				"\nUse help to know more\n",
				username);
			return (1);
		default:
			break;
	}
	return (0);
}

int		processString(char *str, char **parsed, char **parsedpipe)
{
	char	*strpiped[2];
	int		piped;

	piped = 0;
	piped = parsePipe(str, strpiped);
	if (piped)
	{
		parseSpace(strpiped[0], parsed);
		parseSpace(strpiped[1], parsedpipe);
	}
	else
	{
		parseSpace(str, parsed);
	}
	if (ownCmdHandler(parsed))
		return (0);
	else
		return (1 + piped);
}

void	execArgs(char **parsed)
{
	pid_t	pid;

	pid = fork();  // forking a child
	if (pid == -1)
	{
		printf("\nFailed forking child");
		return;
	}
	else if (pid == 0)
	{
		if (execvp(parsed[0], parsed) < 0)
			printf("\nCould not execute command");
		exit(0);
	}
	else
	{
		wait(NULL);  // waiting for child to terminate
		return;
	}
}

void	execArgsPiped(char **parsed, char **parsedpipe)
{
	// 0 is read end, 1 is write end
	int		pipefd[2];
	pid_t	p1;
	pid_t	p2;

	if (pipe(pipefd) < 0)
	{
		printf("\nPipe could not be initialized");
		return;
	}
	p1 = fork();
	if (p1 < 0)
	{
		printf("\nCould not fork");
		return;
	}
	if (p1 == 0)
	{
		// child 1 is executing
		// it only needs to write at the write end
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		if (execvp(parsed[0], parsed) < 0)
		{
			printf("\nCould not execute command 1");
			exit(0);
		}
	}
	else
	{
		// parent executing
		p2 = fork();
		if (p2 < 0)
		{
			printf("\nCould not fork");
			return;
		}
		// child 2 executing
		// it only needs to read the the read end
		if (p2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDOUT_FILENO);
			close(pipefd[0]);
			if (execvp(parsedpipe[0], parsedpipe) < 0)
			{
				printf("\nCould not execute command 2");
				exit(0);
			}
		}
		else
		{
			// parent executing, waiting fot two children
			wait(NULL);
			wait(NULL);
		}
	}
}

int		main(void)
{
	char	inputString[MAXCOM];
	char	*parsedArgs[MAXLIST];
	char	*parsedArgsPiped[MAXLIST];
	int		execFlag;

	execFlag = 0;
	init_shell();
	while (1)
	{
		printDir();  // print shell line
		if (takeInput(inputString))  // take input
			continue;
		// process input
		// execFlag returns: 
		// 0 if builtin or no command,
		// 1 if simple command
		// 2 if include any pipe
		execFlag = processString(inputString, parsedArgs, parsedArgsPiped);
		// execute command
		if (execFlag == 1)
			execArgs(parsedArgs);
		if (execFlag == 2)
			execArgsPiped(parsedArgs, parsedArgsPiped);
	}
	return(0);
}