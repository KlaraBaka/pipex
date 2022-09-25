/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:48:38 by radriann          #+#    #+#             */
/*   Updated: 2022/03/30 16:11:31 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_pid
{
	int		end[2];
	pid_t	cmd1;
	pid_t	cmd2;
	int		f1;
	int		f2;
	char	*cmd;
	char	**cmd_path;
	char	**cmd_args;
	char	*envppath;
}	t_pid;

int		main(int argc, char **argv, char **envp);
char	*find_path(char **envp);
void	childe2_process(t_pid pid, char **argv, char **envp);
void	child_process(t_pid pid, char **argv, char **envp);
char	*get_cmd(char **path, char *cmd);
int		error_return(char *err);
void	err_or_perror(char *err);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	ft_free_path_p(t_pid *pid);
void	ft_free_c(t_pid *pid);
void	close_pipes(t_pid *pid);

#endif