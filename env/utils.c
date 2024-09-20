/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:00:14 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/20 13:09:12 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_index(char *type, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(type);
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], type, len) == 0
			&& (env[i][len] == '=' || env[i][len] == '\0'))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

void	existing_env_update(char *temp, char *value,
		t_minishell_data *mini_data, int index)
{
	free(mini_data->envp[index]);
	if (value != NULL)
	{
		mini_data->envp[index] = ft_strjoin(temp, value);
	}
	else
	{
		mini_data->envp[index] = ft_strdup(temp);
	}
	if (mini_data->envp[index] == NULL)
		error(E_ALLOC, NULL);
}

void	new_env_update(char *temp, char *value, t_minishell_data *mini_data,
		int env_count)
{
	char	**new_env;
	int		i;

	new_env = malloc(sizeof(char *) * (env_count + 2));
	if (new_env == NULL)
		error(E_ALLOC, NULL);
	i = 0;
	while (i < env_count)
	{
		new_env[i] = mini_data->envp[i];
		i++;
	}
	if (value != NULL)
		new_env[env_count] = ft_strjoin(temp, value);
	else
		new_env[env_count] = ft_strdup(temp);
	if (new_env[env_count] == NULL)
		error(E_ALLOC, NULL);
	new_env[env_count + 1] = NULL;
	free(mini_data->envp);
	mini_data->envp = new_env;
}

void	env_update(char *type, char *value, t_minishell_data *mini_data)
{
	char	*temp;
	int		index;
	int		env_count;

	temp = ft_strjoin(type, "=");
	if (temp == NULL)
		error(E_ALLOC, NULL);
	index = env_index(type, mini_data->envp);
	if (index >= 0)
		existing_env_update(temp, value, mini_data, index);
	else
	{
		env_count = 0;
		while (mini_data->envp[env_count] != NULL)
			env_count++;
		new_env_update(temp, value, mini_data, env_count);
	}
	free(temp);
}

char	*get_env(char **env, char *type)
{
	static char	buffer[4096];
	int			i;
	int			len;

	len = ft_strlen(type);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], type, len) == 0 && env[i][len] == '-')
		{
			ft_strlcpy(buffer, env[i] + len + 1, sizeof(buffer));
			return (buffer);
		}
		i++;
	}
	return (NULL);
}
