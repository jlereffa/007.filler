/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_raw_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 15:36:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/29 16:53:33 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_filler_raw	*handle_raw_lst(t_filler_raw *raw, char *content)
{
	if (!raw)
	{
		if (!(raw = (t_filler_raw*)malloc(sizeof(t_filler_raw))))
			return (NULL);
		raw->s = content;
		raw->prev = NULL;
		raw->next = NULL;
		return (raw);
	}
	while (raw->next)
		raw = raw->next;
	if (!(raw->next = handle_raw_lst(raw->next, content)))
		return (NULL);
	raw->next->prev = raw;
	raw = raw->next;
	return (raw);
}
