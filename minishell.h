/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:03:41 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/20 14:05:04 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/inc/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>

# define ERR_SYNTX_MSG "minishell: syntax error near unexpected token `%c'\n"
# define ERR_SYNTX_MSG_FT "minishell: syntax error unclosed quotes\n"
# define ERR_SYNTX_MSG_RE_H \
	"minishell: syntax error near unexpected token \
`%s'\n"
# define TERMINAL_NAME "minishell: No such file or directory\n"
# define ERROR_EXPORT_MSG \
	"export: usage: export [-nf]\
[name[=value] ...] or export -p"
# define BUFFER_SIZE 1024
# define DEBUG 0
# define LOOP 1

extern int				g_global_sig;

typedef enum s_type
{
	WORD,
	PIPE = '|',
	R_DIR_IN = '<',
	R_DIR_OUT = '>',
	R_DIR_APPEND,
	H_DOC,
	ERR,
	EOL,
	SIG_QOT = '\'',
	DOB_QOT = '\"',
	BCK_SLH = '\\',
	ENV_VAR = '$',
}						t_type;

typedef enum e_error_type
{
	E_SYNTAX,
	E_CMD,
	E_PERMISSION,
	E_EXPORT,
	E_ALLOC,
	E_UNSET,
	E_EXIT,
	E_CD,
}						t_error_type;
typedef enum s_error_cod
{
	ERR_SYNTX_COD = 258,
	CMD_NOT_FOUND = 127,
	CMD_NOT_EXE = 126,
	CTRL_C = 130,
}						t_error_cod;

typedef struct s_token
{
	t_type				type;
	char				*val;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_command
{
	char				**args;
	struct s_command	*next;
	struct s_command	*prev;
	int					fd_infile;
	int					fd_outfile;
}						t_ast;

typedef struct s_tree
{
	t_type				type;
	struct s_tree		*left;
	struct s_tree		*right;
	t_token				*token;
	char				**append;
	char				*cmd;
	char				*in;
	char				*out;
	char				*limit;
}						t_tree;

typedef struct s_mini_data
{
	char				*terminal_name;
	char				*input;
	char				*readline;
	pid_t				*pids;
	int					**fds;
	char				**envp;
	int					exit_cd;
	int					exit_status;
	t_token				*tokens;
	t_tree				*binary_tree;
	t_ast				*cmds;
	int					out_fd;
	int					in_fd;
	char				*pwd;
	char				*home;
}						t_minishell_data;

typedef struct s_lexer_data
{
	char				*line;
	int					pos;
	int					dquote;
	int					squote;
}						t_lexer_data;

typedef struct s_hosname
{
	char				**cmd_args;
	char				*res;

}						t_hostname;

// builtins
void					ft_cd(char **input, t_minishell_data *mini_data);
void					ft_echo(char **input, t_minishell_data *mini_data);
void					ft_env(char **input, t_minishell_data *mini_data);
void					ft_pwd(char **cmd, t_minishell_data *mini_data);
void					ft_exit(char *input, t_minishell_data *mini_data);

// environment
int						env_index(char *type, char **env);
void					existing_env_update(char *temp, char *value,
							t_minishell_data *mini_data, int index);
void					new_env_update(char *temp, char *value,
							t_minishell_data *mini_data, int env_count);
void					env_update(char *type, char *value, t_minishell_data *mini_data);
char					*get_env(char **env, char *type);

// error handling
void					builtin_error_msg(t_error_type error_type, char *error_msg);
void					redir_msg(char *file, t_minishell_data *mini_data, int exit_cd);
void					error(t_error_type type, char *input);
void					free_exit(char *msg, t_minishell_data *mini_data, char *exit_status);
void					close_exit(int *fd, char *msg, t_minishell_data *mini_data, char *exit_status);
void					free_array(char **array);
void					free_tokenlist(t_token **token_list);
void					free_tree(t_tree *tree);
void					free_binary(t_tree *tree);
void					free_mini_data(t_minishell_data *mini_data);

// exit
// int						is_digit(char *str);
// long long				ft_atoll(const char *str, bool *error);

// parsing
int						is_ok_parsing(t_minishell_data *mini_dto);
void					unshift_element(char **args, int *pos);
char					*get_env_value(char **envp, char *env_var);
int						file_type_check(char *path);
int						file_permission_check(char *path);
int						passed_ast_cmds_generation(t_minishell_data *mini_dto);
int						add_new_node_to_ast(t_token **tokens, t_ast **cmds_head);
void					init_new_ast_node(t_ast **cmd);
int						init_args(t_token **tokens, t_ast **cmds_head);
int						create_2d_args_null_term(t_token **tokens, t_ast **cmds_head, int i);
int						passed_expansion_process(t_minishell_data *mini_dto);
int						is_needed_expansion(t_minishell_data *mini_dto, char **args, int *flag_rf);
char					*expansion_process_succeeded(t_minishell_data *mini_dto, char *arg,
						char **to_expand, int *flag_rf);
char					*process_single_quotes(char *arg, int *i, char **to_expand);
char					*ft_strncat(char *s1, char *s2, int n);
int						passed_lexical_analysis(t_minishell_data *mini_dto);
void					init_lexer_dto(t_lexer_data *lexer_dto, char *str);
int						passed_redirections_process(t_minishell_data *mini_dto);
int						manage_out_append_to_file(t_ast *head_cmds, int *i);
int						manage_heredoc_in_from_file(t_ast *head_cmds, t_minishell_data *mini_dto, int *i);
void					unshift_n_element(char **args, int *pos, int n);
int						manage_heredoc(int fd, char *delimiter, t_minishell_data *mini_dto, int j);
int						passed_syntactical_analysis(t_minishell_data *mini_dto);
int						passed_pipe_errors(t_token *token);
int						passed_rediriection_error(t_token *token);
t_token					*get_next_token(t_lexer_data *l_dto);
t_token					*create_token(t_type type, char *val, t_token *next, t_token *prev);
t_token					*get_token_word(t_lexer_data *lexer_dto);
void					manage_quotes(t_lexer_data *lexer_dto);
void					free_token_list(t_token *tokens);

// terminal
void					error_print(char *s, t_minishell_data *mini);
void					init_terminal(t_minishell_data *mini_dto);

//utils
char					*get_pwd_from_getcwd(void);
char					*get_home_from_getcwd(void);
void					init_mini_data(t_minishell_data *min_dto, char *envp[]);
int						ft_is_end_ch_envp(int ch);

// main
int						main(int argc, char *argv[], char *envp[]);

#endif
