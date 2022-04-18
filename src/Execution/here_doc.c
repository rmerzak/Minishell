/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:56:39 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/18 17:17:46 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	here_doc(char *delimiter, int *fd)
{
	char	*str;

	signal_init_here();
	while (1)
	{
		str = readline("heredoc> ");
		if (!ft_strcmp(str, delimiter))
			break ;
		ft_putendl_fd(str, fd[1]);
		free(str);
	}
	close(fd[0]);
	close(fd[1]);
	return (1);
}
