/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:20:08 by awali-al          #+#    #+#             */
/*   Updated: 2020/11/03 10:35:48 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

int		hash_add(char *cmd, char *path, char **env)
{
	char	*file;
	char	*add;
	char	*tmp;
	int		fd;

	if ((fd = get_hfd(NULL, env, O_APPEND)) == -1)
		return (-1);
	add = ft_strappend(cmd, '=');
	tmp = ft_strjoin(add, path);
	ft_strdel(add);
	add = ft_strappend(tmp, -2);
	ft_strdel(tmp);
	write(fd, add, ft_strlen(add));
	ft_strdel(add);
	close(fd);
	return (0);
}
