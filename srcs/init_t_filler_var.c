/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_filler_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:32:44 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 17:40:32 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	init_t_filler_var(t_filler_var *v)
{
	if (v->loop_nb > 0)
	{
		del_and_set_to_null_map(&v->plateau);
		del_and_set_to_null_map(&v->piece);
		del_and_set_to_null_t_piece(&v->t_piece);
		if (!v->is_1_player_game)
			v->enemy_token_to_chase = v->player_token == 'O' ? 'x' : 'o';
		else
			v->enemy_token_to_chase = 'X';
	}
	else
		v->loop_nb++;
	v->plateau = NULL;
	v->plateau_height = 0;
	v->plateau_lenght = 0;
	v->piece = NULL;
	v->piece_height = 0;
	v->piece_lenght = 0;
	v->t_piece = NULL;
	v->enemy_token_is_found = 0;
}
