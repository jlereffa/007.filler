/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token_if_possible.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 12:25:51 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/08 13:08:08 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int	try_to_place_token(t_filler_token *to_place, t_filler_token
			*placed_tokens, t_filler_var *v)
{
	int	placed;

	placed = 0;
	while (placed < to_place->sum)
	{

	}
}

int			place_token_if_possible(t_filler_token *placed_tokens, t_filler_var *v)
{
	while (placed_tokens)
	{
		find_angle_to_handle_token_to_place_and_sort(placed_tokens,
		&v->to_place, E_COORD_X, E_COORD_Y)
		if (try_to_place_token(v->to_place, placed_tokens))
			return (1);
		placed_tokens = placed_tokens->next;
	}
	return (0);
}
