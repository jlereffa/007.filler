/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_raw.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:26:50 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/31 16:31:34 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	del_and_set_to_null_raw(t_filler_raw **raw)
{
	t_filler_raw	*tmp;

	while (*raw)
	{
		tmp = *raw;
		if ((*raw)->prev && (*raw)->next)
		{
			(*raw)->next->prev = (*raw)->prev;
			(*raw)->prev->next = (*raw)->next;
			*raw = (*raw)->prev;
		}
		else if ((*raw)->prev && !(*raw)->next)
		{
			(*raw)->prev->next = NULL;
			*raw = (*raw)->prev;
		}
		else if (!(*raw)->prev && (*raw)->next)
		{
			(*raw)->next->prev = NULL;
			*raw = (*raw)->next;
		}
		else
			*raw = NULL;
		free(tmp);
	}
}
