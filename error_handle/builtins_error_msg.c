/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_error_msg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:27:29 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/18 14:04:19 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_error_msg(t_error_type error_type, char *error_msg)
{
	ft_putstr_fd("minishell: ", 2);
	if (error_type == E_EXPORT)
	{
		ft_putstr_fd("export: not a valid identifier: ", 2);
		ft_putendl_ft(error_msg, 2);
	}
	if (error_type == E_UNSET)
	{
		ft_putstr_fd("unset: not a valid identifier: ", 2);
		ft_putendl_fd(error_msg, 2);
	}
	if (error_type == E_CD)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putendl_fd(error_msg, 2);
	}
	if (error_type == E_EXIT)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(error_msg, 2);
		ft_putendl_fd(": numeric argument requiered", 2);
	}
}

void	redir_msg(char *file, t_minishell_data *mini_data, int exit_cd)
{
	printf("minishell: %s: no such file or directory\n", file);
	mini_data->exit_cd = exit_cd;
}
