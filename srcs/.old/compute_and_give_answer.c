/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_and_give_answer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 12:13:59 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/08 15:39:01 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	compute_and_give_answer(t_filler_var *v)
{
	find_enemy_token_position(v);//VALID
	if (v->loop_nb == 1)
		if (!(add_player_first_token_to_placed_tokens_lst(v)))//VALID
			return (0);
	sort_placed_tokens_by_closeness_with_target(&v->placed_tokens, v);//VALID
	if(!(place_token_if_possible(v->placed_tokens, v)))
		return (0);
	return (1);
}
