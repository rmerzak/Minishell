/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:24:04 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/18 17:38:43 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

static void	shell_head(void)
{
	static int	first_time = 1;
	char		*clear_screen;

	if (first_time)
	{
		clear_screen = "\e[1;1H\e[2J";
		write (1, clear_screen, 12);
		first_time = 0;
		printf("\n");
		printf("███╗   ███╗██╗███╗  ██╗██╗ █████");
		printf("█╗██╗  ██╗███████╗██╗     ██╗\n");
		printf("████╗ ████║██║████╗ ██║██║██╔══");
		printf("══╝██║  ██║██╔════╝██║     ██║\n");
		printf("██╔████╔██║██║██╔██╗██║██║╚███");
		printf("██╗ ███████║█████╗  ██║     ██║\n");
		printf("██║╚██╔╝██║██║██║╚████║██║ ╚══");
		printf("═██╗██╔══██║██╔══╝  ██║     ██║\n");
		printf("██║ ╚═╝ ██║██║██║ ╚███║██║████");
		printf("██╔╝██║  ██║███████╗███████╗███████╗\n");
		printf("╚═╝     ╚═╝╚═╝╚═╝  ╚══╝╚═╝╚═══");
		printf("══╝ ╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n");
		printf("\n");
	}
}

static char	*get_cmd(void)
{
	char	*str;

	str = readline("\033[0;33mMinishell\033[0;32m ⎇ \033[4;0m");
	if (str && *str)
		add_history (str);
	return (str);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;

	(void) argv;
	if (argc != 1)
	{
		print_error(argv[1], "No such file or directory");
		return (127);
	}
	shell_head();
	initialisation(envp);
	while (1)
	{
		signal_handler();
		cmd = get_cmd();
		parser(cmd);
		g_shell.cmd_list_head = g_shell.cmd_list;
		execution();
		clean_cmd_list(g_shell.cmd_list_head);
		g_shell.cmd_list_head = NULL;
	}
	return (0);
}
