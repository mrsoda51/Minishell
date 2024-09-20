/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:27:48 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/20 09:50:47 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(char **input, t_minishell_data *mini_data)
{
	int		i;
	char	*env_entry;

	i = 0;
	mini_data->exit_cd = 0;
	if (input[0] != NULL)
	{
		ft_putendl_fd("env: too many arguments", 2);
		mini_data->exit_cd = 2;
		return ;
	}
	while (mini_data->envp[i] != NULL)
	{
		env_entry = mini_data->envp[i];
		if (ft_strchr(env_entry, '=') != NULL)
			printf("%s\n", env_entry);
		i++;
	}
}

void	ft_pwd(char **cmd, t_minishell_data *mini_data)
{
	char	cwd[PATH_MAX];

	mini_data->exit_cd = 0;
	if (cmd[0] != NULL)
	{
		ft_putendl_fd("minishell: too many arguments", 2);
		mini_data->exit_cd = 2;
		return ;
	}
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		ft_putendl_fd("minishell: pwd: error getting path", 2);
		mini_data->exit_cd = 1;
	}
	else
	{
		printf("%s\n", cwd);
	}
}
