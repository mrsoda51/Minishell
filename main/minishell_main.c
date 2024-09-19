/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimoran <rsimoran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:26:16 by rsimoran          #+#    #+#             */
/*   Updated: 2024/09/02 20:26:18 by rsimoran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "math.h"

int	g_global_sig = 0;

int	main(int argc, char *argv[], char *envp[])
{
	t_minishell_data	minishell_data;
	int					exit_cod;

	(void)argv;
	exit_cod = 1;
	if (argc != 1 || !*envp)
		return (exit_cod);
	init_mini_data(&minishell_data, envp);
	rl_bind_key('\t', rl_complete);
	using_history();
	init_terminal(&minishell_data);
	clear_history();
	return (exit_cod = minishell_data.exit_cd, printf("exit\n"), exit_cod);
}
