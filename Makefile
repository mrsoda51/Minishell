# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 10:02:13 by ahusic            #+#    #+#              #
#    Updated: 2024/09/24 16:51:40 by ahusic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RL_FLAGS = -lreadline
INCLUDE = -L $(LIBFT_PATH) -lft

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

BINDIR = bin
PARSEDIR = $(BINDIR)/parsing
ERRORDIR = $(BINDIR)/error_handle
ENVDIR = $(BINDIR)/env
BUILDDIR = $(BINDIR)/builtins
EXECDIR = $(BINDIR)/execution
MAINDIR = $(BINDIR)/main

SRCS =		builtins/cd.c \
			builtins/echo.c \
			builtins/env_pwd.c \
			builtins/exit.c \
			builtins/export.c \
			env/utils.c \
			env/utils2.c \
			error_handle/builtins_error_msg.c \
			error_handle/error.c \
			error_handle/free_close_exit.c \
			main/minishell_main.c \
			parsing/ast_parse.c \
			parsing/cmds_handler.c \
			parsing/minishell_expansion.c \
			parsing/minishell_lexical_analysis.c \
			parsing/minishell_redirections.c \
			parsing/minishell_syntactical_analysis.c \
			parsing/minishell_token_handler.c \
			utils/minishell_utils.c \
			utils/minishell_utils_1.c \

OBJS = $(SRCS:%.c=$(BINDIR)/%.o)

all: $(NAME)

.SILENT:

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS) $(INCLUDE) $(RL_FLAGS)
		echo $(GREEN)"Building $(NAME)"$(DEFAULT);

$(LIBFT):
		make -C $(LIBFT_PATH)

$(BINDIR) $(PARSEDIR) $(BUILDDIR) $(EXECDIR) $(MAINDIR) $(ERRORDIR) $(ENVDIR):
		mkdir -p $@

$(BINDIR)/%.o: %.c | $(BINDIR) $(PARSEDIR) $(BUILDDIR) $(EXECDIR) $(MAINDIR) $(ERRORDIR) $(ENVDIR)
	$(CC) $(CFLAGS) -c $< -o $@

submodule:
		git submodule update --init --recursive

clean:
		make clean -C $(LIBFT_PATH)
		rm -rf $(BINDIR)
		echo $(RED)"Removing $(NAME) object files"$(DEFAULT);

fclean: clean
		rm -f $(NAME)
		make fclean -C $(LIBFT_PATH)
		echo $(RED)"Removing $(NAME)"$(DEFAULT);

re: fclean all
		echo $(GREEN)"Rebuilding everything"$(DEFAULT);

.PHONY: all clean fclean re

# COLORS
DEFAULT = "\033[39m"
GREEN = "\033[32m"
RED = "\033[31m"
