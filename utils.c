/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:25:24 by radriann          #+#    #+#             */
/*   Updated: 2022/03/30 18:01:34 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_c(t_pid *pid)
{
	int	i;

	i = 0;
	while (pid->cmd_args[i])
	{
		free(pid->cmd_args[i]);
		i++;
	}
	free(pid->cmd_args);
	free(pid->cmd);
}

void	ft_free_path_p(t_pid *pid)
{
	int	i;

	i = 0;
	close(pid->f1);
	close(pid->f2);
	while (pid->cmd_path[i])
	{
		free(pid->cmd_path[i]);
		i++;
	}
	free(pid->cmd_path);
}

void	close_pipes(t_pid *pid)
{
	close(pid->end[0]);
	close(pid->end[1]);
}

int	error_return(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	err_or_perror(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}
