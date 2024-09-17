/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:11:23 by ahusic            #+#    #+#             */
/*   Updated: 2023/10/24 17:21:09 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*duplicate;

	len = ft_strlen(s1);
	duplicate = (char *)malloc(len + 1);
	if (duplicate == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(duplicate, s1, len + 1);
	return (duplicate);
}
