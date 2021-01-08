/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_norm_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:12:17 by arochdi           #+#    #+#             */
/*   Updated: 2020/12/13 20:42:13 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_21sh.h"
#include "../../inc/builtins.h"
#include "../../inc/parse.h"
#include "../../inc/ast.h"
#include "../../inc/exec.h"
#include "../../inc/ft_free.h"
#include "../../inc/readline.h"
#include "../../inc/expansion.h"

int		exp_err(char *err)
{
	ft_print(STDERR, "%s\n", err);
	return (1);
}

int		norming_shiiiiiiiit(char **arg, char **word, int start)
{
	char	*tmp;
	char	*tmp2;

	if (((ft_strlen((tmp = ft_strtrim(*word))) != ft_strlen(*word)) ||
		((*arg)[start + 2] == '?' && (ft_isalnum((*arg)[start + 3]) ||
		(*arg)[start + 3] == '_'))) || !ft_strlen(*word))
	{
		tmp ? ft_strdel(&tmp) : 0;
		return (exp_err("Shell: Bad substitution"));
	}
	if (ft_strchri(tmp, '?') > 0 && ft_strstri(tmp, ":?") < 0)
	{
		tmp2 = ft_strndup(tmp, ft_strchri(tmp, '?'));
		if (!param_is_set(tmp2))
		{
			tmp ? ft_strdel(&tmp) : 0;
			tmp2 ? ft_strdel(&tmp2) : 0;
			return (exp_err("Shell : parameter is null or not set"));
		}
		*word ? ft_strdel(word) : 0;
		*word = ft_strdup(tmp2);
		tmp2 ? ft_strdel(&tmp2) : 0;
	}
	tmp ? ft_strdel(&tmp) : 0;
	return (0);
}

void	ft_expans_replace(char **argument, char *to_change, int start, int end)
{
	char	*first;
	char	*second;

	first = ft_strndup(*argument, start);
	second = ft_strjoin(to_change, *argument + end);
	ft_strdel(argument);
	*argument = ft_strjoin(first, second);
	first ? ft_strdel(&first) : 0;
	second ? ft_strdel(&second) : 0;
}

int		ilegal_do(char *word, char c)
{
	int		i;

	i = 0;
	while (word[++i])
	{
		if (ft_isalnum(word[i]) || word[i] == c || word[i] == '_')
			return (0);
		else
			word[i] = '\0';
	}
	return (1);
}

int		ques_dollar(char **argument)
{
	char	*tmp;

	tmp = str_dollar_sub(ft_strjoin("$", *argument));
	tmp = free_remove_quot(tmp);
	if ((*argument)[0] == '+' || (*argument)[0] == '-' || (*argument)[0] == '%'
		|| (*argument)[0] == '*' || (*argument)[0] == '|'
		|| (*argument)[0] == '\\' || (*argument)[0] == '/'
		|| (*argument)[0] == -3 || (*argument)[0] == -2)
	{
		tmp ? ft_strdel(&tmp) : 0;
		return (exp_err("Shell: Bad substitution"));
	}
	ft_strdel(argument);
	*argument = tmp;
	return (0);
}
