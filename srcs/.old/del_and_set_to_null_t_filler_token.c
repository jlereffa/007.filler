/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_t_filler_token.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:28:52 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 19:59:34 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	del_and_set_to_null_t_filler_token(t_filler_token **token)
{
	t_filler_token	*tmp;

	while (*token)
	{
		tmp = *token;
		if ((*token)->prev && (*token)->next)
		{
			(*token)->next->prev = (*token)->prev;
			(*token)->prev->next = (*token)->next;
			*token = (*token)->prev;
		}
		else if ((*token)->prev && !(*token)->next)
		{
			(*token)->prev->next = NULL;
			*token = (*token)->prev;
		}
		else if (!(*token)->prev && (*token)->next)
		{
			(*token)->next->prev = NULL;
			*token = (*token)->next;
		}
		else
			*token = NULL;
		free(tmp);
 	}
}
