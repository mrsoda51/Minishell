/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:41:10 by ahusic            #+#    #+#             */
/*   Updated: 2023/11/21 23:03:20 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char *format, va_list args)
{
	int	print_len;

	print_len = 0;
	if (*format == '\0')
		return (-1);
	if (*format == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (*format == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (*format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	else if (*format == 'd' || *format == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (*format == 'x' || *format == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), *format));
	else if (*format == '%')
		return (write(1, format, 1));
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;
	int		i;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_format(&str[i + 1], args);
			i++;
		}
		else
			count += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
