/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:47:13 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/18 14:28:43 by ahusic           ###   ########.fr       */
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
	//need to make update environment functions
	update_env_var("OLDPWD", old_path, mini_data);
	update_env_var("PWD", new_path, mini_data);
	return (EXIT_SUCCESS);
}

