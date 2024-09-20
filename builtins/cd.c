/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:47:13 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/20 13:55:04 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	cd_path(char *old_path, char *new_path, t_minishell_data *mini_data)
{
	if (chdir(new_path) == -1)
	{
		if (access(new_path, F_OK) == -1)
		{
			builtin_error_msg(E_CD, "no such file or directory");
			return (EXIT_FAILURE);
		}
		builtin_error_msg(E_CD, "not a directory");
		return (EXIT_FAILURE);
	}
	env_update("OLDPWD", old_path, mini_data);
	env_update("PWD", new_path, mini_data);
	return (0);
}

char	*get_new_path(char *input, t_minishell_data *mini_data)
{
	char	*new_path;

	new_path = NULL;
	if (input == NULL)
		new_path = NULL;
	else if (*input == '~' && *(input + 1) == '\0')
		new_path = get_env(mini_data->envp, "HOME");
	else if (*input == '-' && *(input + 1) == '\0')
	{
		new_path = get_env(mini_data->envp, "OLDPWD");
		if (new_path != NULL)
			printf("%s\n", new_path);
	}
	else
		new_path = input;
	if (new_path == NULL)
		builtin_error_msg(E_CD, "path not set");
	return (new_path);
}

void	ft_cd(char **input, t_minishell_data *mini_data)
{
	int		arg_count;
	char	*new_path;
	char	old_path[PATH_MAX];

	arg_count = 0;
	mini_data->exit_status = 0;
	while (input[arg_count] != NULL)
		arg_count++;
	if (arg_count > 1)
	{
		builtin_error_msg(E_CD, "too many arguments");
		mini_data->exit_status = 2;
		return ;
	}
	if (getcwd(old_path, PATH_MAX) == NULL)
	{
		builtin_error_msg(E_CD, "error getcwd");
		mini_data->exit_status = 1;
		return ;
	}
	new_path = get_new_path(input[0], mini_data);
	if (new_path == NULL || cd_path(new_path, old_path, mini_data) != 0)
		mini_data->exit_status = 1;
}
