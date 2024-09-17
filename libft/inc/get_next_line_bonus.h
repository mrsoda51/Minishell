/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:56:44 by ahusic            #+#    #+#             */
/*   Updated: 2024/01/17 20:27:26 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1025
# endif

char	*get_next_line(int fd);
char	*read_data(int fd, char *save);
char	*take_line(char *save);
char	*delete_line(char *save);

//utils
int		ft_line_len(char *s);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str, char *buf);

#endif
