/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:44:52 by ahusic            #+#    #+#             */
/*   Updated: 2023/10/28 17:02:28 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	size_t			len;
	unsigned int	i;
	char			*result;

	len = ft_strlen(s);
	if (s == NULL || f == NULL)
	{
		return (NULL);
	}
	result = (char *)malloc(len + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}
