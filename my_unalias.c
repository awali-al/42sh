/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unalias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 07:28:20 by awali-al          #+#    #+#             */
/*   Updated: 2020/03/13 08:58:25 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int	free_node(t_alias *rm)
{
	ft_strdel(&rm->alias);
	ft_strdel(&rm->value);
	free(rm);
	return (0);
}

static int	free_alias(void)
{
	t_alias	*tmp;

	tmp = g_alias->next;
	while (g_alias)
	{
		free_node(g_alias);
		g_alias = tmp;
		g_alias ? tmp = g_alias->next : 0;
	}
	return (0);
}

static int	remove_alias(char *cmd)
{
	t_alias	*tmp;
	t_alias	*rm;

	tmp = g_alias;
	if (!ft_strcmp(cmd, tmp->alias))
	{
		g_alias = tmp->next;
		free_node(tmp);
	}
	else
		while (tmp->next)
		{
			if (!ft_strcmp(cmd, tmp->next->alias))
			{
				rm = tmp->next;
				tmp->next = rm->next;
				free_node(rm);
				return (0);
			}
			tmp = tmp->next;
		}
	return (0);
}

static int	erralias(char *cmd, int n)
{
	if (n == 1)
		ft_putendl("unalias: not enough arguments");
	else if (n == 2)
		ft_putendl("unalias: -a: too many arguments");
	else
	{
		ft_putstr("unalias: no such hash table element: ");
		ft_putendl(cmd);
	}
	return (n);
}

int			my_unalias(char **line)
{
	int		ret;
	int		i;

	ret = 0;
	if (!line[1])
		return (erralias(NULL, 1));
	if (!ft_strcmp(line[1], "-a"))
	{
		if (line[2])
			return (erralias(NULL, 2));
		else
			return (free_alias());
	}
	else
	{
		i = 0;
		while (line[++i])
		{
			if (alias_check(line[i], -1))
				ret = (erralias(line[1], 3));
			else
				remove_alias(line[i]);
		}
	}
	return (ret);
}
