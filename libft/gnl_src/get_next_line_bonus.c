/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:12:39 by ahusic            #+#    #+#             */
/*   Updated: 2024/01/17 20:22:15 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*delete_line(char *save)
{
	char	*new_s;
	int		i;
	int		j;

	if (!save)
		return (NULL);
	i = ft_line_len(save);
	new_s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!new_s)
		return (NULL);
	j = 0;
	if (save[i] == '\n')
		i++;
	while (save[i] != '\0')
		new_s[j++] = save[i++];
	new_s[j] = '\0';
	free (save);
	return (new_s);
}

char	*take_line(char *save)
{
	char	*line;
	int		i;

	i = ft_line_len(save);
	if (!save)
		return (NULL);
	if (save[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_data(int fd, char *save)
{
	char	*buff;
	int		r_byte;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	r_byte = 1;
	while (!ft_strchr(save, '\n') && r_byte)
	{
		r_byte = read(fd, buff, BUFFER_SIZE);
		if (r_byte == -1)
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[r_byte] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save[fd] = read_data(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = take_line(save[fd]);
	save[fd] = delete_line(save[fd]);
	if (line[0] == '\0')
	{
		free(save[fd]);
		save[fd] = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
