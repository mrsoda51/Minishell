# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 20:11:05 by ahusic            #+#    #+#              #
#    Updated: 2024/04/02 16:31:04 by ahusic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc

GNL_DIR = gnl_src
PRINTF_DIR = printf_src
LIBFT_DIR = libft_src

LIBFT_SRCS = $(addprefix $(LIBFT_DIR)/, \
		ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c fT_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_putchar_fd.c ft_putendl.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmampi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c)

GNL_SRCS = $(addprefix $(GNL_DIR)/, \
		get_next_line_bonus.c get_next_line_utils_bonus.c)

PRINTF_SRCS = $(addprefix $(PRINTF_DIR)/, \
		ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_ptr.c \
		ft_print_str.c ft_print_unsigned.c ft_printf.c)

SRCS = $(LIBFT_SRCS) $(GNL_SRCS) $(PRINTF_SRCS)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
