/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_chck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 02:39:55 by awali-al          #+#    #+#             */
/*   Updated: 2020/11/03 10:46:57 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

char	*hash_chck(char *cmd, char *file, char **env)
{
	char	**table;
	char	*tmp;
	int		i;

	table = hash_table(file, env);
	if (table)
	{
		tmp = ft_strappend(cmd, '=');
		i = 0;
		while (table[i] != ft_strstr(table[i], tmp))
			i++;
		ft_strdel(tmp);
		if (table[i])
		{
			tmp = ft_strdup(table[i] + ft_strlen(cmd) + 1);
			ft_str2del(table);
			return (tmp);
		}
		ft_str2del(table);
	}
	return (NULL);
}
