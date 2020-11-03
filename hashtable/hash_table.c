/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:10:40 by awali-al          #+#    #+#             */
/*   Updated: 2020/11/03 10:40:22 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

int		get_hfd(char *file, char **env, int o)
{
	char	*str;
	int		ret;
	int		i;

	if (!file)
	{
		i = 0;
		while (env[i] != ft_strstr(env[i], "HOME="))
			i++;
		str = ft_strjoin(env[i] + 5, "/.hash");
	}
	else
		str = ft_strdup(file);
	ret = open(str, o);
	ft_strdel(str);
	return (ret);
}

char		**hash_table(char *file, char **env)
{
	char	**hash;
	char	*path;
	char	*buf;
	char	*tmp;
	int		fd;

	if ((fd = get_hfd(file, env, O_RDONLY)) == -1)
		return (NULL);
	while (read(fd, buf, 10000))
	{
		tmp = path;
		path = ft_strjoin(tmp, buf);
		ft_strdel(tmp);
		ft_strdel(buf);
	}
	close(fd);
	hash = ft_strchr(path, -2) ? ft_strsplit(path, -2) : NULL;
	ft_strdel(path);
	return (hash);
}
