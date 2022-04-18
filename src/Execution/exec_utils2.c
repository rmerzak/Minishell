/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:23:38 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/18 17:14:31 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	close_fds(int **fds)
{
	int	i;

	i = 0;
	if (fds)
	{
		while (fds[i])
		{
			close(fds[i][0]);
			close(fds[i][1]);
			i++;
		}
	}
}

void	wait_pids(pid_t	*pids, int nmb)
{
	int	i;
	int	status;

	i = 0;
	status = g_shell.status;
	if (pids)
	{
		while (i < nmb)
		{
			waitpid(pids[i], &status, 0);
			i++;
		}
		if (g_shell.status != status)
			g_shell.status = WEXITSTATUS(status);
		free(pids);
	}
}

void	cmd_end_works(int **fds, pid_t *pids, int i)
{
	if (g_shell.fd_read != -10)
	{
		close (g_shell.fd_read);
		g_shell.fd_read = -10;
	}
	if (g_shell.fd_write != -10)
	{
		close(g_shell.fd_write);
		g_shell.fd_write = -10;
	}
	close_fds(fds);
	wait_pids(pids, i);
	dup2(g_shell.stdin, STDIN_FILENO);
	dup2(g_shell.stdout, STDOUT_FILENO);
	i = 0;
	if (fds)
	{
		while (fds[i])
			free(fds[i++]);
		free(fds);
	}
}
