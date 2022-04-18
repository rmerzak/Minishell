/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:25:07 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/18 16:58:33 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	print_error(char *arg, char *err_name)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(err_name, STDERR_FILENO);
}

void	exit_with_error(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
	clear_all(&g_shell);
	exit(1);
}

int	len_2d_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	file_check(char *file_path, int mode)
{
	struct stat	stats;

	if (stat(file_path, &stats) == 0)
	{
		if (S_ISDIR(stats.st_mode) == 1)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(file_path, STDERR_FILENO);
			ft_putendl_fd(" Is a directory ", STDERR_FILENO);
			return (126);
		}
	}
	if (mode && !access(file_path, 0))
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(file_path, STDERR_FILENO);
		ft_putendl_fd(" No such file or directory ", STDERR_FILENO);
		return (127);
	}
	return (0);
}
