/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_and_give_answer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 12:13:59 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 19:25:11 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int	add_first_token_to_placed_tokens_list(t_filler_var *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (v->plateau[i] && !v->player_token_is_found)
	{
		while (v->plateau[i][j] && !v->player_token_is_found)
		{
			if (v->plateau[i][j] == v->player_token)
			{
				
			}
			j++;
		}
		i++;
		j = 0;
	}
}

static void	find_enemy_token_position(t_filler_var *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (v->plateau[i] && !v->enemy_token_is_found)
	{
		while (v->plateau[i][j] && !v->enemy_token_is_found)
		{
			if (v->plateau[i][j] == v->enemy_token_to_chase)
			{
				E_COORD_X = i;
				E_COORD_Y = j;
				v->enemy_token_is_found = 1;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

int	determine_and_give_answer(t_filler_var *v)
{
	find_enemy_token_position(v);
	if (!v->loop_nb)
	{
		if (!(v->placed_token = add_first_token_to_placed_tokens_list(v)))
			return (0);
	}
	return (1);
}
