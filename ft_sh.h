/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awali-al <awali-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:23:07 by awali-al          #+#    #+#             */
/*   Updated: 2020/03/13 08:55:40 by awali-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <dirent.h>
# include <stdio.h>

# include "libft/libft.h"

typedef struct		s_alias
{
	char			*alias;
	char			*value;
	struct s_alias	*next;
}					t_alias;

extern t_alias		*g_alias;

int					my_type(char **line);
int					alias_check(char *cmd, int n);
int					my_alias(char **line);
int					my_unalias(char **line);

#endif
