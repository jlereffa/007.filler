/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_raw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 14:55:41 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/30 16:18:48 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	del_raw(t_filler_raw **raw)
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
