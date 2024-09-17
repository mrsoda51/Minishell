/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:12:18 by ahusic            #+#    #+#             */
/*   Updated: 2023/11/17 22:35:32 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char *str)
{
	int	count_chars;

	count_chars = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
			count_chars++;
		}
	}
	return (count_chars);
}
