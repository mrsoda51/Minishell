/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:58:30 by ahusic            #+#    #+#             */
/*   Updated: 2023/10/26 20:25:42 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	const char	*start;
	const char	*end;
	size_t		i;
	char		*trimmed;

	len = ft_strlen(s1);
	start = s1;
	end = s1 + len - 1;
	i = len;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*start && ft_strchr(set, *start))
		start++;
	while (end > start && ft_strchr(set, *end))
		end--;
	i = end - start + 1;
	trimmed = (char *)malloc(i + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_memcpy(trimmed, start, i);
	trimmed[i] = '\0';
	return (trimmed);
}
