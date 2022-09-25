/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:50:07 by radriann          #+#    #+#             */
/*   Updated: 2022/03/30 18:01:09 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	char	real_path;

	real_path = ft_strncmp("PATH=", *envp, 4);
	if (!real_path)
		exit(1);
	while (ft_strncmp("PATH=", *envp, 4))
		envp++;
	if (!envp)
		err_or_perror("comman not found\n");
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pid	pid;

	if (argc != 5)
		err_or_perror("Check number of arguments\n");
	pid.f1 = open(argv[1], O_RDONLY);
	pid.f2 = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pid.f1 < 0)
		err_or_perror(argv[1]);
	if (pid.f2 < 0)
		err_or_perror(argv[4]);
	if (pipe(pid.end) < 0)
		err_or_perror("wrong pipe\n");
	pid.envppath = find_path(envp);
	pid.cmd_path = ft_split(pid.envppath, ':');
	pid.cmd1 = fork();
	if (pid.cmd1 == 0)
		child_process(pid, argv, envp);
	pid.cmd2 = fork();
	if (pid.cmd2 == 0)
		childe2_process(pid, argv, envp);
	close_pipes(&pid);
	waitpid(pid.cmd1, NULL, 0);
	waitpid(pid.cmd2, NULL, 0);
	ft_free_path_p(&pid);
	return (0);
}

void	child_process(t_pid pid, char *argv[], char *envp[])
{
	pid.cmd_args = ft_split(argv[2], ' ');
	pid.cmd = get_cmd(pid.cmd_path, pid.cmd_args[0]);
	if (!pid.cmd)
	{
		ft_free_c(&pid);
		error_return("command not found\n");
		exit(127);
	}
	dup2(pid.end[1], 1);
	close(pid.end[0]);
	dup2(pid.f1, 0);
	if (execve(pid.cmd, pid.cmd_args, envp) < 0)
	{
		err_or_perror("execve failed\n");
		exit(127);
	}
}

void	childe2_process(t_pid pid, char *argv[], char *envp[])
{
	pid.cmd_args = ft_split(argv[3], ' ');
	pid.cmd = get_cmd(pid.cmd_path, pid.cmd_args[0]);
	if (!pid.cmd)
	{
		ft_free_c(&pid);
		error_return("command not found\n");
		exit(127);
	}
	dup2(pid.end[0], 0);
	close(pid.end[1]);
	dup2(pid.f2, 1);
	if (execve(pid.cmd, pid.cmd_args, envp) < 0)
	{
		err_or_perror("execve failed\n");
		exit(127);
	}
}
