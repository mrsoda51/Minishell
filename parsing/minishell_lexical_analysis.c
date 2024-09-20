/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lexical_analysis.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:24:49 by rsimoran          #+#    #+#             */
/*   Updated: 2024/09/20 14:01:09 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	passed_lexical_analysis(t_minishell_data *mini_dto)
{
	t_lexer_data	lexer_dto;
	t_token			*head;
	t_token			*next;

	init_lexer_dto(&lexer_dto, mini_dto->readline);
	mini_dto->tokens = get_next_token(&lexer_dto);
	mini_dto->tokens->prev = NULL;
	if (!lexer_dto.line || !mini_dto->tokens)
		return (0);
	head = mini_dto->tokens;
	while (head->type != EOL)
	{
		head->next = get_next_token(&lexer_dto);
		if (!head->next || head->type == ERR)
			return (ft_putendl_fd(ERR_SYNTX_MSG_FT, 2),
				mini_dto->exit_cd = ERR_SYNTX_COD,
				null_check_free_str(lexer_dto.line), 0);
		next = head;
		head = head->next;
		head->prev = next;
	}
	if (DEBUG)
		print_token_list(mini_dto->tokens, "TOKENS");
	return (null_check_free_str(lexer_dto.line), 1);
}

void	init_lexer_dto(t_lexer_data *lexer_dto, char *str)
{
	lexer_dto->line = ft_strdup(str);
	lexer_dto->pos = 0;
	lexer_dto->dquote = 0;
	lexer_dto->squote = 0;
}
