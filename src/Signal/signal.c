/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:24:46 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/18 17:01:06 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	sig_init(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	write(2, "  \n", 3);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_shell.status = 1;
}

void	signal_init(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}

void	signal_handler(void)
{
	signal(SIGINT, sig_init);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_init_here(void)
{
	signal(SIGINT, SIG_DFL);
}
