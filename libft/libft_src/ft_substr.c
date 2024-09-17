/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:11:50 by ahusic            #+#    #+#             */
/*   Updated: 2023/10/24 17:49:35 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	original_len;
	char	*substring;

	original_len = ft_strlen(s);
	if (start >= original_len)
	{
		return (ft_strdup (""));
	}
	if (start + len > original_len)
	{
		len = original_len - start;
	}
	substring = (char *)malloc(len + 1);
	if (substring == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}
