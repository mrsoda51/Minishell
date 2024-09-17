/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 22:33:45 by ahusic            #+#    #+#             */
/*   Updated: 2023/11/17 22:14:13 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

static int	ft_count_hexlen(unsigned long num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		count++;
		num = num / 16;
	}
	return (count);
}

static void	ft_convert_down(unsigned long num, char *hexstring)
{
	const char	*hexchars;
	int			len;
	int			i;

	len = ft_count_hexlen(num);
	hexchars = "0123456789abcdef";
	i = len - 1;
	while (i >= 0)
	{
		hexstring[i] = hexchars[num % 16];
		num /= 16;
		i--;
	}
	hexstring[len] = '\0';
}

int	ft_print_ptr(unsigned long ptr)
{
	char	*hexstring;
	int		count;

	count = 0;
	if (ptr == 0)
	{
		count += write(1, "0x0", 3);
		return (count);
	}
	hexstring = (char *)malloc(ft_count_hexlen(ptr) + 3);
	if (hexstring == NULL)
		return (-1);
	count += write(1, "0x", 2);
	ft_convert_down(ptr, hexstring);
	count += write(1, hexstring, ft_strlen(hexstring));
	free(hexstring);
	return (count);
}
