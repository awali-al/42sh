/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:35:44 by aminewalial       #+#    #+#             */
/*   Updated: 2020/10/19 20:05:52 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int     type(char **av)
{
    if (av[1][0] == '-')
		return (0);
    else if (av[1][0] == '!')
		return (1);
    else
		return (2);
}

int     my_test(char *cmd, char **av, char **env)
{
    if (!av[1] || (av[1] && !av[1][0] && !av[2]))
		return (1);
	else if (av[2])
}
