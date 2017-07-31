/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_t_piece.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:28:52 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/31 16:30:42 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	del_and_set_to_null_t_piece(t_filler_piece **t_piece)
{
	t_filler_piece	*tmp;

	while (*t_piece)
	{
	tmp = *t_piece;
	if ((*t_piece)->prev && (*t_piece)->next)
	{
		(*t_piece)->next->prev = (*t_piece)->prev;
		(*t_piece)->prev->next = (*t_piece)->next;
		*t_piece = (*t_piece)->prev;
	}
	else if ((*t_piece)->prev && !(*t_piece)->next)
	{
		(*t_piece)->prev->next = NULL;
		*t_piece = (*t_piece)->prev;
	}
	else if (!(*t_piece)->prev && (*t_piece)->next)
	{
		(*t_piece)->next->prev = NULL;
		*t_piece = (*t_piece)->next;
	}
	else
		*t_piece = NULL;
	free(tmp);
 	}
}
