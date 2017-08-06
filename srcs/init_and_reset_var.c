/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_reset_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:32:44 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/06 11:17:28 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	first_init_var(t_filler_var *v)
{
	v->plateau = NULL;
	v->token_map = NULL;
	v->to_place = NULL;
	v->placed_tokens = NULL;
}

void	init_and_reset_var(t_filler_var *v)
{
	if (!v->loop_nb)
		first_init_var(v);
	else
	{
		del_and_set_to_null_array_table(&v->plateau);
		del_and_set_to_null_array_table(&v->token_map);
		del_and_set_to_null_t_filler_token(&v->to_place);
	}
	v->plateau_height = 0;
	v->plateau_lenght = 0;
	v->token_map_height = 0;
	v->token_map_lenght = 0;
	v->player_token_is_found = 0;
	v->enemy_token_to_chase_coord_x = 0;
	v->enemy_token_to_chase_coord_y = 0;
	v->enemy_token_is_found = 0;
	v->loop_nb++;
}
