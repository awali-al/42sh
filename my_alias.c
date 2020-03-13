/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_alias.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 02:48:02 by awali-al          #+#    #+#             */
/*   Updated: 2020/03/13 07:28:41 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int				alias_check(char *cmd, int n)
{
	t_alias		*a;

	a = g_alias;
	while (a)
	{
		if (!ft_strcmp(cmd, a->alias))
		{
			if (n != -1)
			{
				ft_putstr(a->alias);
				if (n)
					ft_putchar('=');
				else
					ft_putstr(" is an alias for ");
				ft_putendl(a->value);
			}
			return (0);
		}
		a = a->next;
	}
	return (1);
}

static t_alias	*new_alias(char *alias, char *e)
{
	t_alias		*ret;

	ret = (t_alias*)malloc(sizeof(t_alias));
	ret->alias = ft_strndup(alias, e - alias);
	ret->value = ft_strdup(e + 1);
	ret->next = NULL;
	return (ret);
}

int			my_alias(char **line)
{
	t_alias		*tmp;
	char		*e;
	int			ret;
	int			i;

	ret = 0;
	tmp = g_alias;
	while (tmp->next)
	{
		!line[1] ? alias_check(tmp->alias, 1) : 0;
		!line[1] && !tmp->next->next ? alias_check(tmp->next->alias, 1) : 0;
		tmp = tmp->next;
	}
	i = 0;
	while (line[++i])
	{
		if (!(e = ft_strchr(line[i], '=')))
			ret = alias_check(line[i], 1);
		else
		{
			tmp->next = new_alias(line[i], e);
			tmp = tmp->next;
		}
	}
	return (ret);
}
