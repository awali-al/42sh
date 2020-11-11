/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:10:40 by awali-al          #+#    #+#             */
/*   Updated: 2020/11/11 13:40:29 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"

int		get_fd(int flag)
{
	char	*str;
	int		ret;

	str = ft_strjoin(getenv("HOME"), "/.hash");
	if (flag == 'r')
		ret = open(str, O_RDONLY | O_CREAT, S_IRWXU);
	else if (flag == 'a')
		ret = open(str, O_WRONLY | O_APPEND);
	else
		ret = open(str, O_TRUNC);
	ft_strdel(&str);
	return (ret);
}

static char	*get_line(int fd)
{
	char	*ret;
	char	buf[HASH_BUFF + 1];
	char	*tmp;
	int		n;
	
	ret = ft_strnew(1);
	while ((n = read(fd, buf, HASH_BUFF)) > 0)
	{
		tmp = ret;
		buf[n] = '\0';
		ret = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	close(fd);
	return (ret);
}

char		**hash_table(void)
{
	char	**hash;
	char	*path;
	int		fd;

	fd = get_fd('r');
	if (fd == -1)
		return (NULL);
	path = get_line(fd);
	if (path && ft_strchr(path, SEPARATOR))
		hash = ft_strsplit(path, SEPARATOR);
	else
		hash = NULL;
	ft_strdel(&path);
	return (hash);
}
