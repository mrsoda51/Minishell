/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:05:29 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/19 11:45:11 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_exit(char *msg, t_minishell_data *mini_data, char *exit_status)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	ft_exit(exit_status, mini_data);
}

void	close_exit(int *fd, char *msg, t_minishell_data *mini_data,
				char *exit_status)
{
	close(fd[0]);
	close(fd[1]);
	free_exit(msg, mini_data, exit_status);
}
