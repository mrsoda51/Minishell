/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:35:46 by ahusic            #+#    #+#             */
/*   Updated: 2023/10/22 15:47:37 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *) malloc (count * size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero (ptr, count * size);
	return (ptr);
}
