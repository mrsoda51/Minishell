/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:06:37 by ahusic            #+#    #+#             */
/*   Updated: 2023/10/24 19:35:56 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;

	a = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == a)
		{
			return ((char *)s);
		}
		s++;
	}
	if (a == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
