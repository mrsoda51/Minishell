/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:35:32 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/24 17:59:35 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	valid_key(char *input_key)
{
	int	index;

	index = 0;
	if (!ft_isalpha(input_key[index]) && input_key[index] != '_')
		return (0);
	while (input_key[index] != '\0')
	{
		if (!ft_isalnum(input_key[index]) && input_key[index] != '_')
			return (0);
		index++;
	}
	return (1);
}

char	*copy_env_wout_index(char **envp, char **new_envp, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (envp[i] != NULL)
	{
		if (i != j)
		{
			new_envp[j] = ft_strdup(envp[i]);
			if (new_envp[j] == NULL)
			{
				free_array(new_envp);
				error(E_ALLOC, NULL);
				return (NULL);
			}
			j++;
		}
		else
			free(envp[i]);
		i++;
	}
	free(envp);
	return (new_envp);
}

char	**remove_env(char **envp, int index)
{
	char	**new_envp;
	int		i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	new_envp = ft_calloc(i, sizeof(char *));
	if (!new_envp)
		return (error(E_ALLOC, NULL), NULL);
	new_envp = copy_env_wout_index(envp, new_envp, index);
	return (new_envp);
}

void	ft_unset(char **args, t_minishell_data *mini_data)
{
	int	envp_index;
	int	arg_index;

	arg_index = 0;
	mini_data->exit_status = 0;
	if (args == NULL)
		return ;
	while (args[arg_index] != NULL)
	{
		envp_index = env_index(args[arg_index], mini_data->envp);
		if (envp_index != -1)
		{
			if (!valid_key(args[arg_index]))
			{
				builtin_error_msg(E_UNSET, args[arg_index]);
				mini_data->exit_status = 2;
			}
			mini_data->envp = remove_envp(mini_data->envp, envp_index);
		}
		arg_index++;
	}
}
