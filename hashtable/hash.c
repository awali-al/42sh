/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:27:35 by awali-al          #+#    #+#             */
/*   Updated: 2020/11/03 10:53:48 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

static int	hash_print(char *file, char **env)
{
	char	**table;
	int		i;

	i = 0;
	table = hash_table(NULL, env);
	if (!table)
		ft_putendl("hash: hash table empty");
	else
		while (table[i])
			ft_putendl(table[i++]);
	ft_str2del(table);
	return (0);
}

int			hash(char *cmd, char **av, char **env)
{
	int		ret;

	(void)cmd;
	ret = 0;
	if (!av[1])
		ret = hash_print(NULL, env);
	else
	{
		
	}
	return (ret);
}
