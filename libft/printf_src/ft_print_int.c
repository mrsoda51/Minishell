/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:24:25 by ahusic            #+#    #+#             */
/*   Updated: 2023/11/17 22:17:47 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_digitcount(int n)
{
	int	num;
	int	digits;

	num = n;
	digits = 1;
	if (n < 0)
		num = -n;
	while (num >= 10)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

void	ft_printnum(int n)
{
	if (n < 0)
	{
		ft_putchar ('-');
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_printnum(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_print_int(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n == 2147483647)
	{
		write(1, "2147483647", 10);
		return (10);
	}
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	i = ft_digitcount(n);
	ft_printnum(n);
	if (n < 0)
		return (i + 1);
	else
		return (i);
}
