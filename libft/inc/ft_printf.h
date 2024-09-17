/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:10:39 by ahusic            #+#    #+#             */
/*   Updated: 2023/11/16 19:29:32 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_print_char(char c);
int	ft_print_hex(unsigned int num, const char format);
int	ft_print_int(int n);
int	ft_print_ptr(unsigned long pointer);
int	ft_print_str(const char *str);
int	ft_print_unsigned(unsigned int num);
int	ft_printf(const char *str, ...);

#endif
