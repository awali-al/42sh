/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazouaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 21:33:31 by sazouaka          #+#    #+#             */
/*   Updated: 2019/12/03 21:33:45 by sazouaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_21sh.h"
#include "../../inc/builtins.h"
#include "../../inc/parse.h"
#include "../../inc/ast.h"
#include "../../inc/exec.h"
#include "../../inc/ft_free.h"
#include "../../inc/readline.h"

int		ft_set_var_env(char **av, int env)
{
	if (env == 2)
		return (0);
	if (ft_set_node(av, env) == 0)
		return (1);
	ft_set_lastnode(av, env);
	return (1);
}

void	print_g_var(void)
{
	t_variable	*node;

	node = g_var.var;
	while (node)
	{
		ft_print(STDOUT, "%s=%s\n", node->key, node->value);
		node = node->next;
	}
}

int		ft_setenv(char **flag)
{
	if (flag[1] != NULL && flag[2] != NULL && flag[3] != NULL)
	{
		ft_putstr_fd("setenv: Too many arguments.\n", STDERR);
		return (1);
	}
	else
	{
		if (flag[1] == NULL)
			print_g_var();
		else
		{
			if (!(ft_isalpha(flag[1][0])) && flag[1][0] != '_')
			{
				ft_putstr_fd("setenv: Variable name must begin ", 2);
				ft_putstr_fd("with a letter.\n", 2);
				return (1);
			}
			else if (ft_set_alnum(flag) == 1)
				return (1);
			else
				ft_set_var_env(flag, 0);
		}
	}
	return (0);
}
