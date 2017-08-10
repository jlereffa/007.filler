/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t_filler_raw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 20:58:38 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 20:59:27 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_filler_raw	*set_t_filler_raw(t_filler_raw *raw, char *content)
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
	if (!(raw->next = set_t_filler_raw(raw->next, content)))
		return (NULL);
	raw->next->prev = raw;
	raw = raw->next;
	return (raw);
}
