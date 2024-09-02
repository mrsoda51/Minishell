/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimoran <rsimoran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:26:04 by rsimoran          #+#    #+#             */
/*   Updated: 2024/09/02 20:26:08 by rsimoran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_mini_data(t_minishell_data *mini_dto, char *envp[])
{

	mini_dto->exit_cd = 0;
	mini_dto->out_fd = STDOUT_FILENO;
	mini_dto->in_fd = STDIN_FILENO;
	mini_dto->pwd = get_pwd_from_getcwd();
	mini_dto->home = get_home_from_getcwd();
	
	mini_dto->terminal_name = ft_strdup("minishell-0.1$ ");
}

int	ft_is_end_ch_envp(int ch)
{
	int	flag;

	flag = 1;
	if (!(ch >= 48 && ch <= 57) && !((ch >= 65 && ch <= 90) || (ch >= 97
				&& ch <= 122)) && ch != 95)
		flag = 0;
	return (flag);
}