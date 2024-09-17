/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:11:53 by ahusic            #+#    #+#             */
/*   Updated: 2023/10/29 20:05:03 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	unsigned int	num;

	size = ft_length(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	num = n;
	if (n < 0)
	{
		str[0] = '-';
		num = n * (-1);
	}
	if (num == 0)
		str[0] = '0';
	str[size] = '\0';
	while (num != 0)
	{
		size--;
		str[size] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
