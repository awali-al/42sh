/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 08:45:33 by aminewalial       #+#    #+#             */
/*   Updated: 2020/10/20 18:51:38 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	file_types(char o, char *av)
{
	struct stat	file;
	int			ret;

	if (lstat(av, &file))
		return (1);
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
	ret = !ft_strlen(av) && o == 'z' ? 0 : ret;
	return (ret);
}

int	unary_operator_check(char *av)
{
	if (!av[2] && ((av[1] > 'a' && av[1] < 'h') || av[1] == 'L' || av[1] == 'p'
			|| av[1] == 'r' || av[1] == 'S' || av[1] == 's' || av[1] == 'u' ||
			av[1] == 'w' || av[1] == 'x' || av[1] == 'z'))
		return (0);
	else
	{
		ft_putstr_fd("test: unknown condition: ", 2);
		ft_putendl_fd(av, 2);
		return (1);
	}
}

int	binary_operator_check(char *av)
{
	if (ft_strcmp(av[2]))
		return (0);
	else
	{
		ft_putstr_fd("42sh: condition expected: ", 2);
		ft_putendl_fd(av, 2);
		return (1);
	}
}
