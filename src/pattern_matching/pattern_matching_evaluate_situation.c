/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_matching_evaluate_situation.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozaazaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:49:22 by ozaazaa           #+#    #+#             */
/*   Updated: 2020/12/16 23:04:43 by ozaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/pattern_matching.h"

int	finished_or_only_trailing_wilcards(t_list_node *range)
{
	t_range_match *current_range;

	while (range)
	{
		current_range = range->content;
		if (current_range->match_count != MATCH_ZERO_OR_MORE)
			return (0);
		range = range->next;
	}
	return (1);
}

int	evaluate_current_situation(t_list_node *range, char *to_match,
		int match_index)
{
	int	len;

	len = ft_strlen(to_match);
	if (!range)
	{
		if (match_index >= len)
			return (SITUATION_STATUS_SUCCESS);
		return (SITUATION_STATUS_FAIL);
	}
	else if (match_index >= len)
	{
		if (finished_or_only_trailing_wilcards(range))
			return (SITUATION_STATUS_SUCCESS);
		return (SITUATION_STATUS_FAIL);
	}
	return (SITUATION_STATUS_NONE);
}
