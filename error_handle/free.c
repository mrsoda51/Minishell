/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahusic <ahusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:31:20 by ahusic            #+#    #+#             */
/*   Updated: 2024/09/20 13:24:15 by ahusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_tokenlist(t_token **token_list)
{
	t_token	*temp;

	if (token_list == NULL || *token_list == NULL)
		return ;
	while (*token_list)
	{
		temp = (*token_list)->next;
		if ((*token_list)->val != NULL)
			free((*token_list)->val);
		free(*token_list);
		*token_list = temp;
	}
}

void	free_tree(t_tree *tree)
{
	if (tree == NULL)
		return ;
	if (tree->cmd != NULL)
		free_array(tree->cmd);
	if (tree->append != NULL)
		free_array(tree->append);
	if (tree->in != NULL)
		free_array(tree->in);
	if (tree->out != NULL)
		free_array(tree->out);
	if (tree->limit != NULL)
		free(tree->limit);
	tree->cmd = NULL;
	tree->append = NULL;
	tree->in = NULL;
	tree->out = NULL;
	tree->limit = NULL;
}

void	free_binary(t_tree *tree)
{
	if (tree == NULL)
		return ;
	if (tree->type != PIPE)
	{
		free_tree(tree);
		return ;
	}
	free_binary(tree->left);
	free(tree->left);
	tree->left = NULL;
	free_binary(tree->right);
	free(tree->right);
	tree->right = NULL;
}

void	free_mini_data(t_minishell_data *mini_data)
{
	if (mini_data == NULL)
		return ;
	if (mini_data->envp != NULL)
	{
		free_array(mini_data->envp);
		mini_data->envp = NULL;
	}
	if (mini_data->input != NULL)
	{
		free(mini_data->input);
		mini_data->input = NULL;
	}
	free_tokenlist(&(mini_data->tokens));
	if (mini_data->binary_tree != NULL)
	{
		free_binary(mini_data->binary_tree);
		free(mini_data->binary_tree);
	}
	free(mini_data);
}
