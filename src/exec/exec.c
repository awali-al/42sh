/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:13:41 by afaraji           #+#    #+#             */
/*   Updated: 2020/12/10 11:32:21 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_21sh.h"
#include "../../inc/builtins.h"
#include "../../inc/parse.h"
#include "../../inc/ast.h"
#include "../../inc/exec.h"
#include "../../inc/ft_free.h"
#include "../../inc/readline.h"

int		exec_simple_cmd(t_simple_cmd *cmd)
{
	char	**args;
	char	**env;
	char	*cmd_path;

	if (!cmd)
		return (404);
	if (do_simple_cmd(cmd))
		return (1);
	args = get_arg_var_sub(cmd);
	if (!args || !args[0])
		exit(0);
	env = env_to_tab(g_var.var, 0);
	if (is_builtin(args[0]))
	{
		return (builtins(args[0], args, env));
	}
	if (!(cmd_path = get_cmdpath(args[0])))
		return (127);
	execve(cmd_path, args, env);
	ft_print(STDERR, "shell: permission denied: %s\n", args[0]);
	return (126);
}

int		exec_pipe_right(t_pipe_seq *cmd, int pfd[2], pid_t pid_l)
{
	pid_t	pid_r;
	int		status;

	if ((pid_r = fork()) == -1)
		return (2);
	if (pid_r == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], STDIN);
		if (cmd->right->right)
			exec_pipe(cmd->right);
		else
			exit(exec_simple_cmd(cmd->right->left));
	}
	close(pfd[0]);
	close(pfd[1]);
	waitpid(pid_l, NULL, 0);
	waitpid(pid_r, &status, 0);
	exit(WEXITSTATUS(status));
}

int		exec_pipe(t_pipe_seq *cmd)
{
	int		pfd[2];
	pid_t	pid_l;

	if (cmd->right == NULL)
		exit(exec_simple_cmd(cmd->left));
	if (pipe(pfd) != 0)
		return (1);
	if ((pid_l = fork()) == -1)
		return (2);
	if (pid_l == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], STDOUT);
		exit(exec_simple_cmd(cmd->left));
	}
	else
	{
		exec_pipe_right(cmd, pfd, pid_l);
	}
	return (0);
}

int		exec_ast(t_pipe_seq *cmd, int pgid)
{
	int			child;
	int			status;

	status = 0;
	child = fork();
	if (child == 0)
	{
		setpgid(0, pgid);
		exec_pipe(cmd);
	}
	else
	{
		waitpid(child, &status, 0);
	}
	return (status);
}

int		execute(t_and_or *cmd, int pgid)
{
	int dp;
	int ret;

	ret = 0;
	while (cmd)
	{
		dp = cmd->dependent;
		if (!dp || (dp == 1 && !ret) || (dp == 2 && ret))
		{
			ret = exec_ast(cmd->ast, pgid);
		}
		cmd = cmd->next;
	}
	return (ret);
}
