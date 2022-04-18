/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:23:33 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/18 17:13:15 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	is_builtin(char *arg)
{
	if (!ft_strcmp(arg, "echo") || !ft_strcmp(arg, "cd")
		|| !ft_strcmp(arg, "pwd") || !ft_strcmp(arg, "export")
		|| !ft_strcmp(arg, "unset") || !ft_strcmp(arg, "env")
		|| !ft_strcmp(arg, "exit"))
		return (1);
	return (0);
}

static int	get_exec_nmb(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		if (cmd->args[0] && !is_builtin(cmd->args[0]))
			i++;
		cmd = cmd->next;
	}
	return (i);
}

int	len_cmd_list(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		cmd = cmd->next;
		i++;
	}
	return (i);
}

int	init_fds(t_minishell *g_shell)
{
	int	i;
	int	len_cmd;

	i = 0;
	len_cmd = len_cmd_list(g_shell->cmd_list);
	if (len_cmd > 1)
	{
		g_shell->fds = (int **)malloc(sizeof(int *) * len_cmd);
		if (g_shell->fds == NULL)
			exit_with_error("minishell: malloc error");
		while (i < len_cmd - 1)
		{
			g_shell->fds[i] = (int *)malloc(sizeof(int) * 2);
			if (pipe(g_shell->fds[i]) == -1)
			{
				print_error("-", "pipe error");
				g_shell->fds[i] = NULL;
				return (-1);
			}
			i++;
		}
		g_shell->fds[len_cmd - 1] = NULL;
	}
	return (1);
}

int	get_pids_fds(t_cmd *cmd_list)
{
	int	exec_nmb;
	int	i;

	exec_nmb = 0;
	g_shell.pids = NULL;
	g_shell.fds = NULL;
	exec_nmb = get_exec_nmb(cmd_list);
	if (exec_nmb)
	{
		g_shell.pids = (pid_t *)malloc(sizeof(pid_t) * exec_nmb);
		if (g_shell.pids == NULL)
			exit_with_error("minishell : malloc error");
	}
	if (init_fds(&g_shell) == -1)
	{
		i = 0;
		free(g_shell.pids);
		close_fds(g_shell.fds);
		while (g_shell.fds[i])
			free(g_shell.fds[i++]);
		free(g_shell.fds);
		return (0);
	}
	return (1);
}
