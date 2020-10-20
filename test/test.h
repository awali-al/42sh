/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminewalialami <aminewalialami@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:37:26 by aminewalial       #+#    #+#             */
/*   Updated: 2020/10/19 14:16:52 by aminewalial      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>

int     my_test(char *cmd, char **av, char **env);
int     file(char **av);
int		comp(char **av);

#endif
