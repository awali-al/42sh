/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 08:45:33 by aminewalial       #+#    #+#             */
/*   Updated: 2020/10/19 14:14:47 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	file_types(char o, char *av, struct stat file)
{
	int		ret;

	ret = 1;
	ret = S_ISBLK(file.st_mode) && o == 'b' ? 0 : ret;
	ret = S_ISCHR(file.st_mode) && o == 'c' ? 0 : ret;
	ret = S_ISDIR(file.st_mode) && o == 'd' ? 0 : ret;
	ret = S_ISREG(file.st_mode) && o == 'f' ? 0 : ret;
	ret = S_ISLNK(file.st_mode) && o == 'L' ? 0 : ret;
	ret = S_ISFIFO(file.st_mode) && o == 'p' ? 0 : ret;
	ret = S_ISSOCK(file.st_mode) && o == 'S' ? 0 : ret;
	ret = (file.st_mode & S_ISUID) && o == 'u' ? 0 : ret;
	ret = (file.st_mode & S_ISGID) && o == 'g' ? 0 : ret;
	ret = (file.st_mode & S_IRUSR) && o == 'r' ? 0 : ret;
	ret = (file.st_mode & S_IWUSR) && o == 'w' ? 0 : ret;
	ret = (file.st_mode & S_IXUSR) && o == 'x' ? 0 : ret;
	ret = (file.st_size > 0) && o == 's' ? 0 : ret;
	return (ret);
}

static int	option_check(char *av)
{
	if ((av[1] > 'a' && av[1] < 'h') || av[1] == 'L' || av[1] == 'p' ||
			av[1] == 'r' || av[1] == 'S' || av[1] == 's' || av[1] == 'u' ||
			av[1] == 'w' || av[1] == 'x' || av[1] == 'z')
		return (0);
	else
	{
		ft_putstr_fd("test: unknown condition:", 2);
		ft_putendl_fd(av, 2);
		return (1);
	}
}

static int	error_test(char **av)
{
	if (ft_strlen(av[1]) != 1 || av[3])
	{
		if (av[1][3])
		{
			ft_putstr_fd("test: unknown condition: ", 2);
			ft_putendl_fd(av[1], 2);
		}
		else if (!av[1][1])
		{
			if (!av[3])
				ft_putendl_fd("zsh: parse error: condition expected: -", 2);
			else if (av[3] && !av[4])
			{
				ft_putstr_fd("zsh: condition expected: ", 2);
				ft_putendl_fd(av[3], 2);
			}
			else
				ft_putendl_fd("zsh: condition expected: -", 2);
		}
		else if (av[3])
			ft_putendl_fd("test: too many arguments", 2);
		return (1);
	}
	return (0);
}

int     	file(char **av)
{
	struct stat	file;
	
	if (error_test(av) || option_check(av[1]))
		return (2);
	if (av[1][1] == '-z')
	{
		if (ft_strlen(av[2]))
			return (1);
		else
			return (0);
	}
	if (!stat(av[2], &file))
		return (file_types(av[1][1], av[2], file));
	else
		return (1);
}
