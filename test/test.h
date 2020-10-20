/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:37:26 by aminewalial       #+#    #+#             */
/*   Updated: 2020/10/20 18:49:09 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>

int		my_test(char *cmd, char **av, char **env);
int		unary_operator_check(char *av);
int		binary_operator_check(char *av);
int		file_types(char o, char *av);

#endif
