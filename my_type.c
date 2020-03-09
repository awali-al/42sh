/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:21:04 by awali-al          #+#    #+#             */
/*   Updated: 2020/03/09 04:35:51 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static int	built_in(char *cmd)
{
	if (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "echo") ||
			!ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "exit") ||
			!ft_strcmp(cmd, "setenv") || !ft_strcmp(cmd, "type") ||
			!ft_strcmp(cmd, "unsetenv"))
	{
		ft_putstr(cmd);
		ft_putendl(" is a shell builtin");
		return (1);
	}
	return (0);
}

static char	*comp(char *cmd, char *pth, char *dir)
{
	char			*tmp;

	tmp = ft_strjoin(pth, dir);
	free(pth);
	if (!ft_strcmp(cmd, tmp) || !ft_strcmp(cmd, dir))
		return (tmp);
	ft_strdel(&tmp);
	return (NULL);
}

static char	*path(char **arr, char *cmd)
{
	struct dirent	*sd;
	DIR				*dd;
	char			*ret;
	int				i;

	i = 0;
	ret = NULL;
	while (arr[i] && !ret)
	{
		dd = opendir(arr[i]);
		while ((sd = readdir(dd)) && !ret)
			ret = comp(cmd, ft_strjoin(arr[i], "/"), sd->d_name);
		closedir(dd);
		i++;
	}
	return (ret);
}

static int	output(char *cmd, char *pth, int ret)
{
	if (pth)
	{
		ft_putstr(cmd);
		ft_putstr(" is ");
		ft_putendl(pth);
		ret != -1 ? ret = 0 : 0;
	}
	else
	{
		ft_putstr(cmd);
		ft_putendl(" not found");
		ret = -1;
	}
	return (ret);
}

void		my_type(char **line)
{
	char			**arr;
	char			*pth;
	int				ret;
	int				i;

	i = 1;
	ret = 1;
	arr = ft_strsplit(getenv("PATH"), ':');
	while (line[i])
	{
		if (!built_in(line[i]))
		{
			pth = path(arr, line[i]);
			ret = output(line[i], pth, ret);
			ft_strdel(&pth);
		}
		i++;
	}
	exit(ret);
}
