/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:27:33 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/24 16:59:09 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**new_env(char **envp, char *new)
{
	char	**new_envp;
	int		i;
	int		j;

	i = 0;
	while (envp[i])
		i++;
	new_envp = fT_calloc(i + 2, sizeof(char *));
	if (!new_envp)
		return (error(E_ALLOC, NULL), NULL);
	j = 0;
	while (j < i)
	{
		new_envp[i] = ft_strdup(envp[j]);
		if (!new_envp[j])
			return (free_array(new_envp), error(E_ALLOC, NULL), NULL);
		free(envp[j]);
		j++;
	}
	free(envp);
	new_envp[j] = ft_strdup(new);
	if (!new_envp[j])
		return (free_array(new_envp), error(E_ALLOC, NULL), NULL);
	return (new_envp);
}

char	**sort_new(char **envp)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (envp[i] != NULL)
	{
		j = i + 1;
		while (envp[j] != NULL)
		{
			if (ft_strncmp(envp[i], envp[j], t_strlen(envp[i]) + 1) > 0)
			{
				temp = envp[i];
				envp[i] = envp[j];
				envp[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (envp);
}

char	*put_quotes(char *envp)
{
	char	*key;
	char	*value;
	char	*quoted_value;
	char	*res;
	size_t	i;

	i = 0;
	while (envp[i] && envp[i] != '=')
		i++;
	if (envp[i] == '\0')
		return (envp);
	key = ft_substr(envp, 0, i);
	value = ft_strdup(envp + i + 1);
	quoted_value = ft_strjoin("\"", value);
	free(value);
	value = ft_strjoin(quoted_value, "\"");
	free(quoted_value);
	res = ft_strjoin(key, "=");
	free(key);
	quoted_value = ft_strjoin(res, value);
	free(res);
	free(value);
	return (quoted_value);
}
