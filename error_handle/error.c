/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:35:05 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/18 12:49:39 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	error(t_error_type type, char *input)
{
	ft_putstr_fd("minishell: ", 2);
	if (type == E_SYNTAX)
	{
		ft_putstr_fd("syntax error: ", 2);
		ft_putendl_fd(input, 2);
	}
	else if (type == E_PERMISSION)
		ft_putstr_fd("Permission denied: ", 2);
	else if (type == E_ALLOC)
		ft_putstr_fd("Allocation failed: ", 2);
	else
		ft_putstr_fd("Unknown error: ", 2);
}
