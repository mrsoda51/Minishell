/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_terminal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:25:35 by rsimoran          #+#    #+#             */
/*   Updated: 2024/09/20 13:59:30 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error_print(char *s, t_minishell_data *mini)
{
	if (s[0] == '\"' && s[1] == '\"')
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("", 2);
		ft_putendl_fd(": command not found", 2);
		mini->exit_cd = 127;
	}
	if (ft_strncmp(s, "&&", 3) == 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd(s, 2);
		ft_putendl_fd("\'", 2);
		mini->exit_cd = 258;
	}
}

void	init_terminal(t_minishell_data *mini_dto)
{
	while (LOOP)
	{
		g_global_sig = 0;
		mini_dto->readline = readline(mini_dto->terminal_name);
		if (!mini_dto->readline)
			break ;
		if (mini_dto->readline[0] == '\0')
		{
			null_check_free_str(mini_dto->readline);
			continue ;
		}
		add_history(mini_dto->readline);
		if (is_ok_parsing(mini_dto))
		{
			/*
			we need to do executation
			we have to check if the command is a built-in
			we have pepare env for executation
			*/
		}

	}
	return (0);
}
