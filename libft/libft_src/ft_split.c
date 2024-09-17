/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:34:30 by ahusic            #+#    #+#             */
/*   Updated: 2023/10/28 15:26:56 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s == NULL)
	{
		return (0);
	}
	while (*s)
	{
		if (*s == c)
		{
			i = 0;
		}
		else if (!i)
		{
			i = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	**ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char	*ft_cpy(char const *s, size_t len)
{
	size_t	i;
	char	*n;

	i = 0;
	if (!len)
	{
		return (NULL);
	}
	n = malloc(sizeof(char) * (len + 1));
	if (!n)
	{
		return (NULL);
	}
	while (i < len && s[i] != '\0')
	{
		n[i] = s[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	split = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (0);
	while (i < count_words(s, c) && s[start] != '\0')
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		split[i] = ft_cpy(&s[start], end - start);
		if (split[i] == NULL)
			return (ft_free(split));
		start = end;
		i++;
	}
	split[i] = NULL;
	return (split);
}
