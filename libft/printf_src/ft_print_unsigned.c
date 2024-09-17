/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:26:30 by ahusic            #+#    #+#             */
/*   Updated: 2023/11/16 21:58:50 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_digitprint(unsigned int num)
{
	int	nbr_bytes;

	nbr_bytes = 0;
	if (num >= 10)
		nbr_bytes += ft_digitprint(num / 10);
	nbr_bytes += ft_putchar('0' + (num % 10));
	return (nbr_bytes);
}

int	ft_print_unsigned(unsigned int num)
{
	if (num == 0)
		return (ft_putchar('0'));
	else
		return (ft_digitprint(num));
}
