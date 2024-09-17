/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:47:13 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/17 13:58:15 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_error(t_error_type error_type, char *context)
{
	ft_putstr_fd("minishell: ", 2);
	if (error_type == E_CD)
	{
		if (access(context, F_OK) == -1)
		{
			ft_putstr_fd("cd: ", 2);
			ft_putstr_fd(context, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
		else
		{
			ft_putstr_fd("cd: ", 2);
			ft_putstr_fd(context, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
		}
	}
	else
		ft_putstr_fd("An error occurred\n", 2);
}

int	cd_path(char *old_path, char *new_path, t_minishell_data *mini_data)
{
	if (chdir(new_path) == -1)
	{
		handle_error(E_CD, new_path);
		return EXIT_FAILURE;
	}
	//need to make an update environment functions
	update_env_var("OLDPWD", old_path, mini_data);
	update_env_var("PWD", new_path, mini_data);
	return EXIT_SUCCESS;
}
