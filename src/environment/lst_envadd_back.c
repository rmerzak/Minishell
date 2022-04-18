/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_envadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:18:08 by zchbani           #+#    #+#             */
/*   Updated: 2022/04/18 18:31:14 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/minishell.h"

void	lst_envadd_back(t_env_list **list, t_env_list *new)
{
	t_env_list	*tmp;

	if (list)
	{
		if (*list)
		{
			tmp = lst_envlast(*list);
			tmp->next = new;
		}
		else
		{
			*list = new;
		}
	}
}
