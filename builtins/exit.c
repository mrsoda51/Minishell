/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:01:39 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/20 12:36:52 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_digit(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

long long	ft_atoll(const char *str, bool *error)
{
	unsigned long	num;
	int				sign;

	num = 0;
	sign = 1;
	*error = false;
	if (str == NULL)
		return (0);
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	if ((sign == 1 && num > LLONG_MAX)
		|| (sign == -1 && num > 9223372036854775808ULL))
		*error = true;
	return (num * sign);
}

void	ft_exit(char *input, t_minishell_data *mini_data)
{
	unsigned int	exit_code;
	bool			error;

	printf("exit\n");
	exit_code = mini_data->exit_status;
	error = false;
	if (input != NULL)
	{
		if (input[0] != '\0')
			exit_code = 0;
		else
		{
			exit_code = ft_atoll(input, &error);
			if ((is_digit(input) == false && input != NULL) || error == true)
			{
				builtin_error_msg(E_EXIT, input);
				exit_code = 255;
			}
		}
	}
	free_mini_data(mini_data);
	rl_clear_history();
	exit((unsigned char)exit_code);
}
