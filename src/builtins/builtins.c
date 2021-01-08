/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:15:16 by sazouaka          #+#    #+#             */
/*   Updated: 2020/12/09 20:17:49 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_21sh.h"
#include "../../inc/builtins.h"
#include "../../inc/parse.h"
#include "../../inc/ast.h"
#include "../../inc/exec.h"
#include "../../inc/ft_free.h"
#include "../../inc/readline.h"
#include "../../inc/hash_table.h"
#include "../../inc/test.h"

int		ft_export(char **flag, char **env)
{
	int		i;
	char	*key;
	char	*value;

	i = 1;
	if (flag[1] == NULL)
	{
		print_env(env);
		return (0);
	}
	else if (flag[1][0] == '-' && flag[1][1] == 'p' && flag[1][2] == '\0')
		return (print_env_1(env));
	value = NULL;
	while (flag[i])
	{
		if (get_key_value(&key, &value, flag[i]))
			return (1);
		ft_export_2(key, value);
		ft_strdel(&key);
		ft_strdel(&value);
		i++;
	}
	return (0);
}

int		cd_builtin(char **av, char **env)
{
	if (av[1] == NULL)
		return (ft_cd_home(env));
	else
	{
		if (av[1][0] == '-')
		{
			if (av[1][1] == '\0')
				return (ft_cd_old(env));
			else if (av[1][1] == 'P')
				return (ft_cd_1(ft_strdup(av[2]), env));
			else if (av[1][1] == 'L')
				return (ft_cd(av[2], env));
			else
			{
				ft_print(STDERR, "shell: cd: %s: invalid option\n", av[1]);
				ft_print(STDERR, "cd: usage: cd [-L|-P] [dir].\n");
			}
		}
		else
			return (ft_cd(av[1], env));
	}
	return (1);
}

int		builtins_2(char *cmd, char **av)
{
	if (ft_strcmp(cmd, "jobs") == 0)
		return (ft_jobs(av));
	else if (ft_strcmp(cmd, "fg") == 0)
		return (ft_fg(av));
	else if (ft_strcmp(cmd, "bg") == 0)
		return (ft_bg(av));
	else if (ft_strcmp(cmd, "fc") == 0)
		return (ft_fc(av));
	if (ft_strcmp(cmd, "test") == 0)
		return (ft_test(cmd, av));
	else if (ft_strcmp(cmd, "hash") == 0)
		return (ft_hash(cmd, av));
	else if (ft_strcmp(cmd, "type") == 0)
		return (ft_type(av));
	return (42);
}

int		builtins(char *cmd, char **av, char **env)
{
	if (ft_strcmp(cmd, "exit") == 0)
		return (ft_exit(av));
	else if (ft_strcmp(cmd, "echo") == 0)
		return (ft_echo(av));
	else if (ft_strcmp(cmd, "cd") == 0)
		return (cd_builtin(av, env));
	if (ft_strcmp(cmd, "env") == 0)
	{
		print_env(env);
		return (0);
	}
	else if (ft_strcmp(cmd, "setenv") == 0 || ft_strcmp(cmd, "set") == 0)
		return (ft_setenv(av));
	else if (ft_strcmp(cmd, "unsetenv") == 0 || ft_strcmp(cmd, "unset") == 0)
		return (ft_unsetenv(av));
	else if (ft_strcmp(cmd, "export") == 0)
		return (ft_export(av, env));
	else if (ft_strcmp(cmd, "alias") == 0)
		return (ft_alias(av));
	else if (ft_strcmp(cmd, "unalias") == 0)
		return (ft_unalias(av));
	return (builtins_2(cmd, av));
}
