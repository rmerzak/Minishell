/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:22:13 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/18 18:30:41 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

int	envlist_chr(char *key, t_env_list *env_list)
{
	while (env_list)
	{
		if (!ft_strcmp(key, env_list->key))
			return (1);
		env_list = env_list->next;
	}
	return (0);
}

void	change_pwd(char *dest, char *pwd)
{
	t_env_list	*temp;

	temp = (t_env_list *) malloc(sizeof(t_env_list));
	if (NULL == temp)
		exit_with_error("minishell: -: malloc error");
	temp->key = ft_strdup(dest);
	temp->val = ft_strdup(pwd);
	temp->equal = 1;
	change_env_val(temp, &g_shell.env_list);
}

char	*get_pwd(void)
{
	char		*pwd;
	char		buf[4096];

	pwd = getcwd(buf, sizeof(buf));
	if (!pwd)
	{
		g_shell.status = 1;
		perror("minishell: cd: ");
		return (NULL);
	}
	return (pwd);
}

void	change_dir_core(char **args)
{
	char	*temp_pwd;
	char	*error_message;

	temp_pwd = get_pwd();
	if (NULL == temp_pwd)
		return ;
	if (chdir(args[1]) == -1)
	{
		g_shell.status = 1;
		error_message = ft_strjoin("minishell: cd: ", args[1]);
		if (NULL == error_message)
			exit_with_error("minishell: -: malloc error");
		perror(error_message);
		free(error_message);
		return ;
	}
	change_pwd("OLDPWD", temp_pwd);
	temp_pwd = get_pwd();
	if (NULL == temp_pwd)
		return ;
	change_pwd("PWD", temp_pwd);
}

void	change_dir(void)
{
	int		len;
	char	**args;

	args = g_shell.cmd_list->args;
	len = len_2d_str(args);
	if (len > 2)
	{
		print_error("cd", "too many arguments");
		g_shell.status = 1;
		return ;
	}
	else if (2 == len)
	{
		change_dir_core(args);
	}
}
