/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:37:47 by ahusic            #+#    #+#             */
/*   Updated: 2023/11/17 22:29:01 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_hexlen(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

void	ft_puthex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, format);
		ft_puthex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_print_char((num + '0'));
		else
		{
			if (format == 'x')
				ft_print_char((num - 10 + 'a'));
			if (format == 'X')
				ft_print_char((num - 10 + 'A'));
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(num, format);
	return (ft_count_hexlen(num));
}
