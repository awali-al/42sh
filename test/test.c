/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:35:44 by aminewalial       #+#    #+#             */
/*   Updated: 2020/10/20 20:03:20 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	two_args(char **av)
{
	if (!ft_strcmp(av[1], "!"))
	{
		if (!av[2] || (av[2] && !av[2][0]))
			return (1);
	}
	else if (av[1][0] == '-')
	{
		if (unary_operator_check(av[1]))
			return (2);
		else
			files_types(av[1][1], av[2]);
	}
	else
	{
		ft_putstr_fd("42sh: parse error: condition expected: ", 2);
		ft_putendl_fd(av[1], 2);
		return (2);
	}
	return (0);
}

static int	three_args(char **av)
{
	if (ft_strcmp(av[1], "!"))
		return (!two_args(av + 1));
	else if (!ft_strcmp(av[1], "(") && !ft_strcmp(av[3], ")"))
	{
		if (av[2][0])
			return (0);
	}
	else if (binary_operator_check(av[2]))
		return (expression)
	return (1);
}

int			my_test(char *cmd, char **av, char **env)
{
	if (!av[1] || (av[1] && !av[1][0] && !av[2]))
		return (1);
	else if (av[2] && !av[3])
		return (two_args(av));
	else if (av[3] && !av[4])
		return (three_args(av));
	return (0);
}
