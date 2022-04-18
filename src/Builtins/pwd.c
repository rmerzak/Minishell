/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:23:23 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/18 18:31:08 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	pwd(void)
{
	char	*pwd;
	char	buf[4096];

	pwd = getcwd(buf, sizeof(buf));
	if (pwd)
	{
		ft_putendl_fd(buf, STDOUT_FILENO);
		g_shell.status = 0;
	}
	else
	{
		perror("minishell: pwd: ");
		g_shell.status = 127;
	}
}
