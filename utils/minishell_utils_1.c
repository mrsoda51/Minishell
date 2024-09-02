/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsimoran <rsimoran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:25:56 by rsimoran          #+#    #+#             */
/*   Updated: 2024/09/02 20:25:58 by rsimoran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd_from_getcwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (ft_strdup(""));
	return (pwd);
}

char	*get_home_from_getcwd(void)
{
	char	*home;
	char	*pwd;
	char	**tmp;
	char	*tmp2;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (ft_strdup(""));
	tmp = ft_split(pwd, '/');
	tmp2 = ft_strdup("/");
	home = ft_strjoin(tmp2, tmp[0]);
	free(tmp2);
	tmp2 = ft_strjoin(home, "/");
	free(home);
	home = ft_strjoin(tmp2, tmp[1]);
	null_check_free_str(tmp2);
	free_2d(tmp);
	if (home == NULL)
		return (null_check_free_str(pwd), ft_strdup(""));
	null_check_free_str(pwd);
	return (home);
}
