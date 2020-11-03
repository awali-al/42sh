/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:11:01 by awali-al          #+#    #+#             */
/*   Updated: 2020/11/03 10:55:05 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include "libft/libft.h"
# include <fcntl.h>

char	*ft_strappend(char *str, char c);
int		ft_str2del(char **str);

char	**hash_table(char *file, char **env);
char	*hash_chck(char *cmd, char *file, char **env);
int		hash_add(char *cmd, char *path, char **env);
int		get_hfd(char *file, char **env, int o);
int		hash(char *cmd, char **av, char **env);

#endif