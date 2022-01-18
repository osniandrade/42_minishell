while (1)
{
    line_read_aux = get_line(mini.line_read);
    mini.line_read = ft_strtrim(line_read_aux, " ");
    free(line_read_aux);
    if (mini.line_read && *mini.line_read)
    {
        if (mini.tokens)
            free_char_array(mini.tokens);
        mini.tokens = ft_split(mini.line_read, ' ');
        mini.cmd = mini.tokens[0];
        is_builtin(mini.cmd, &mini);
        if (mini.is_builtin == true)
            run_builtin(&mini);
        else
        {
            child_pid = fork();
            if (child_pid == 0)
            {
                ft_execve(&mini);
                child_pid = getpid();
                kill(child_pid, SIGKILL);
            }
            else
                waitpid(child_pid, &stat_loc, WUNTRACED);
}
void    ft_execve(t_struct *mini)
{
    int        i;
    char    *path_aux;

    i = 0;
    while (mini->path[i])
    {
        path_aux = ft_strjoin(mini->path[i], mini->tokens[0]);
        execve(path_aux, &mini->tokens[0], mini->env.env);
        i++;
    }
    printf("%s: command not found\n", mini->line_read);
}