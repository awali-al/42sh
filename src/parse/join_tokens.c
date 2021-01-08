/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:41:39 by afaraji           #+#    #+#             */
/*   Updated: 2020/12/16 12:53:43 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_21sh.h"
#include "../../inc/builtins.h"
#include "../../inc/parse.h"
#include "../../inc/ast.h"
#include "../../inc/exec.h"
#include "../../inc/ft_free.h"
#include "../../inc/readline.h"

t_list_token	*list_sub_malloc(t_list_token *node, t_list_token *start)
{
	t_list_token	*ret;

	ret = (t_list_token *)malloc(sizeof(t_list_token));
	if (!ret)
		return (NULL);
	ret->prec = node;
	ret->is_ok = start->is_ok;
	if (start->data)
		ret->data = ft_strdup(start->data);
	else
		ret->data = NULL;
	ret->type = start->type;
	ret->next = NULL;
	return (ret);
}

t_list_token	*list_sub(t_list_token *start, t_list_token *end)
{
	t_list_token *head;
	t_list_token *node;

	if (!start)
		return (NULL);
	head = NULL;
	while (start)
	{
		if (!head)
		{
			node = list_sub_malloc(NULL, start);
			head = node;
		}
		else
		{
			node->next = list_sub_malloc(node, start);
			node = node->next;
		}
		if (start == end)
			break ;
		start = start->next;
	}
	return (head);
}

void			join_nodes(t_list_token *dst, t_list_token *todel)
{
	char			*tmp;

	tmp = ft_strjoin(dst->data, todel->data);
	ft_strdel(&(dst->data));
	dst->data = tmp;
	dst->type = WORD;
	dst->next = todel->next;
	if (todel->next)
		todel->next->prec = dst;
	free_token_node(&todel);
}

void			re_quoting(t_list_token *list)
{
	char			*tmp;
	char			*delimit;
	t_list_token	*node;

	node = list;
	while (node)
	{
		if (node->type == QUOTE || node->type == DQUOTE)
		{
			tmp = node->data;
			delimit = (node->type == DQUOTE) ? ft_strdup("\375") :
															ft_strdup("\376");
			node->data = ft_4strjoin(delimit, tmp, delimit, "");
			node->type = WORD;
			ft_strdel(&delimit);
			ft_strdel(&tmp);
		}
		node = node->next;
	}
}

void			join_words(t_list_token *token)
{
	t_list_token	*node;
	t_list_token	*tmp;

	re_quoting(token);
	node = token;
	while (node->next)
	{
		if (node->type == WORD || node->type == QUOTE || node->type == DQUOTE)
		{
			tmp = node->next;
			if (tmp->type == WORD || tmp->type == QUOTE || tmp->type == DQUOTE)
			{
				join_nodes(node, tmp);
				node = token;
			}
		}
		if (!(node->next))
			break ;
		node = node->next;
	}
}
