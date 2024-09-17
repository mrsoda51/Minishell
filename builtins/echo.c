/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:51:12 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/13 12:52:55 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_n(char *args)
{
	int	i;

	if (!args || args[0] != '-')
		return (0);
	i = 1;
	while (args[i] == 'n')
		i++;
	return (args[i] == '\0');
}

void	ft_echo(char **input, t_minishell_data *mini_data)
{
	int		i;
	int		option;
	bool	flag;

	i = 0;
	flag = false;
	mini_data->exit_cd = 0;
	option = check_n(input[1]);
	while (input[i])
	{
		if (flag)
			if (printf(" ") == -1)
				mini_data->exit_cd = 1;
		if (printf("%s", input[i]) == -1)
			mini_data->exit_cd = 1;
		flag = true;
		i++;
	}
	if (!option)
		printf("\n");
}
