/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:28:09 by rsimoran          #+#    #+#             */
/*   Updated: 2024/09/19 11:44:20 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/inc/libft.h"
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

typedef struct s_mini_data
{
	char				*terminal_name;
	char				*readline;
	pid_t				*pids;
	int					**fds;
	char				**envp;
	int					exit_cd;
	int					exit_status;
	t_token				*tokens;
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

void					init_mini_data(t_minishell_data *min_dto, char *envp[]);
void					init_terminal(t_minishell_data *mini_dto);
int						is_ok_parsing(t_minishell_data *mini_dto);

// lexical part
int						passed_lexical_analysis(t_minishell_data *mini_dto);
int						passed_syntactical_analysis(t_minishell_data *mini_dto);
void					init_lexer_dto(t_lexer_data *lexer_dto, char *str);
t_token					*get_next_token(t_lexer_data *l_dto);
t_token					*create_token(t_type type, char *val, t_token *next,
							t_token *prev);
t_token					*get_token_word(t_lexer_data *lexer_dto);
void					free_token_list(t_token *tokens);
void					manage_quotes(t_lexer_data *lexer_dto);
void					free_mini_dto(t_minishell_data *mini_dto);
void					free_cmd_list(t_ast *cmds);
int						passed_pipe_errors(t_token *token);
int						passed_rediriection_error(t_token *token);
void					init_new_ast_node(t_ast **cmd);
int						add_new_node_to_ast(t_token **tokens,
							t_ast **cmds_head);
int						passed_ast_cmds_generation(t_minishell_data *mini_dto);
int						init_args(t_token **tokens, t_ast **cmds_head);
int						create_2d_args_null_term(t_token **tokens,
							t_ast **cmds_head, int i);
int						passed_expansion_process(t_minishell_data *mini_dto);
int						is_needed_expansion(t_minishell_data *mini_dto,
							char **args, int *flag_rf);
char					*expansion_process_succeeded(t_minishell_data *mini_dto,
							char *arg, char **to_expand, int *flag_rf);
char					*process_single_quotes(char *arg, int *i,
							char **to_expand);
char					*ft_strncat(char *s1, char *s2, int n);
char					*process_double_quotes(t_minishell_data *mini_dto,
							char *arg, int *i, char **to_expand);
int						process_expansion(t_minishell_data *mini_dto, char *arg,
							int *i, char **to_expand);
char					*get_env_value(char **envp, char *env_var);
int						process_env_variable(t_minishell_data *mini_dto,
							char *arg, int *i, char **to_expand);
int						process_exit_status(int exit_status, int *i,
							char **to_expand);
void					unshift_element(char **args, int *pos);
char					**concat_arrays(char **array_1, char **array_2,
							int start, int *flag_rf);
int						ft_is_end_ch_envp(int ch);
int						passed_redirections_process(t_minishell_data *mini_dto);
void					free_2d(char **args);
int						manage_out_append_to_file(t_ast *head_cmds, int *i);
int						manage_heredoc_in_from_file(t_ast *head_cmds,
							t_minishell_data *mini_dto, int *i);
void					unshift_n_element(char **args, int *pos, int n);
int						manage_heredoc(int fd, char *delimiter,
							t_minishell_data *mini_dto, int j);
int						file_type_check(char *path);
void					ft_update_shell_level(t_minishell_data *mini, int i);
void					ft_upd_shelvl_free(t_minishell_data *mini,
							char *old_lvl_num, char *new_lvl_num);
int						ft_env_stars_with_str(char *envp[], char *str);
void					find_and_replace_env(char **envp, char *to_find,
							char *to_replace);
void					init_envp(char *envp[], int len,
							t_minishell_data *mini_dto);
void					prepare_envp(char *envp[], int index,
							t_minishell_data *mini_dto, int len);

// this are to the terminal format <<Hostname>:<Directory_name> <user$>>
void					init_hostname(t_hostname *hostname, char *str);
char					*get_terminal_name_formated(char *envp[]);
char					*find_user(char *envp[]);
void					free_hostname(t_hostname *hostname);
void					get_hostname_child_process(t_hostname *t_hostname);
char					*get_formated(char *user, char *host, char *pwd);
void					null_check_free_str(char *str);
char					*get_value_after_equal(char *env);
void					wait_all_children(t_minishell_data *mini, int lst_size);
void					close_all_fds(int **fd, int size);
int						has_correct_value(char *str);
int						file_permission_check(char *path);
char					*get_pwd_from_getcwd(void);
char					*get_home_from_getcwd(void);

// mohs - function
// find path
char					*ft_find_path(t_minishell_data *mini, char *arg, int i);
char					*ft_trim_path(char *path);
char					*ft_create_path(char *path, char *command);

//	utils
void					error_print_one_message(char *message, int c,
							t_minishell_data *mini);
void					error_print_message(char *message1, char *message2,
							int c, t_minishell_data *mini);
void					error_print_two_message(char *message1, char *message2,
							int c, t_minishell_data *mini);
char					*ft_getenv(t_minishell_data *mini, char *to_get);
int						ft_lstsize_commands(t_ast *lst);
void					stop(char *message);
int						ft_getenv_set(char **envp, char *to_get);
void					error_print(char *s, t_minishell_data *mini);

// builtins
int						check_n(char *args);
void					ft_echo(char **input, t_minishell_data *mini_data);
void					ft_env(char **input, t_minishell_data *mini_data);
void					ft_pwd(char **cmd, t_minishell_data *mini_data);
int						cd_path(char *old_path, char *new_path,
							t_minishell_data *mini_data);


// error handling
void					error(t_error_type type, char *input);
void					builtin_error_msg(t_error_type error_type,
							char *error_msg);
void					redir_msg(char *file, t_minishell_data *mini_data,
							int exit_cd);
void					free_exit(char *msg, t_minishell_data *mini_data,
							char *exit_status);
void					close_exit(int *fd, char *msg,
							t_minishell_data *mini_data, char *exit_status);

#endif

//need add bunch of stuff maybe we make new ione//
