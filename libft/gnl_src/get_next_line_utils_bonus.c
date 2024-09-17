/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:10:20 by ahusic            #+#    #+#             */
/*   Updated: 2024/01/17 20:12:28 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_line_len(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&(str[i]));
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
	{
		s = (char *)malloc(sizeof(char) * (1));
		s[0] = '\0';
	}
	if (!buf)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(buf)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s)
		while (s[++i] != '\0')
			str[i] = s[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(s) + ft_strlen(buf)] = '\0';
	free(s);
	return (str);
}
