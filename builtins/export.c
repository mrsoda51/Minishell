/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:47:48 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/24 17:32:35 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_key(char *envp, t_minishell_data *mini_data)
{
	int		i;
	char	*key;

	i = 0;
	if (!(ft_isalpha(envp[i]) || envp[i] == '-'))
	{
		builtin_error_msg(E_EXPORT, envp);
		mini_data->exit_status = 1;
		return (NULL);
	}
	while (envp[i] != '\0' && envp[i] != '='
		&& !(envp[i] == '+' && envp[i + 1] == '='))
	{
		if (!(ft_isalnum(envp[i]) || envp[i] == '_'))
		{
			builtin_error_msg(E_EXPORT, envp);
			mini_data->exit_status = 1;
			return (NULL);
		}
		i++;
	}
	key = ft_substr(envp, 0, i);
	return (key);
}

void	plus_handle(t_minishell_data *mini_data,
				char *key, char *envp, int index)
{
	char	*value;
	char	*envp_value;

	value = NULL;
	if (index != -1)
	{
		envp_value = get_env(mini_data->envp, key);
		value = ft_strjoin(envp_value, ft_strchr(envp, '=') + 1);
		env_update(key, value, mini_data);
	}
	else
	{
		value = ft_strjoin(key, ft_strchr(envp, '+') + 1);
		mini_data->envp = new_env(mini_data->envp, value);
	}
	free(value);
}

void	process_export(char *key, char *envp, t_minishell_data *mini_data)
{
	int		index;
	char	*envp_value;

	index = env_index(key, mini_data->envp);
	if (ft_strchr(envp, '+') && *(ft_strchr(envp, '+') + 1) == '=')
	{
		plus_handle(mini_data, key, envp, index);
		return ;
	}
	if (index != -1)
	{
		if (ft_strchr(envp, '='))
			envp_value = ft_strhr(envp, '=') + 1;
		else
			envp_value = NULL;
		env_update(key, envp_value, mini_data);
	}
	else
		mini_data->envp = new_env(mini_data->envp, envp);
}

void	exported_env_print(char **envp)
{
	int		i;
	char	*quoted_envp;

	i = 0;
	envp = sort_new(envp);
	while (envp[i] != NULL)
	{
		quoted_envp = put_quotes(envp[i]);
		printf("declare -x %s\n", quoted_envp);
		if (ft_strchr(quoted_envp, '=') != NULL)
			free(quoted_envp);
		i++;
	}
}

void	ft_export(char **input, t_minishell_data *mini_data)
{
	char	*key;
	int		i;

	mini_data->exit_status = 0;
	i = 0;
	if (input[0] == NULL)
	{
		exported_env_print(mini_data->envp);
		return ;
	}
	while (input[i] != NULL)
	{
		key = get_key(input[i], mini_data);
		process_export(key, input[i], mini_data);
		free(key);
		i++;
	}
}
