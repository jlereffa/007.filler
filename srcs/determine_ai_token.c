/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_ai_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 17:38:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/30 18:15:59 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	init_t_filler_tmp(t_filler_tmp *tmp)
{
	tmp->has_cap_o = 0;
	tmp->has_o = 0;
	tmp->has_cap_x = 0;
	tmp->has_x = 0;
	tmp->x = 0;
	tmp->y = 0;
}

static void	browse_the_plateau_and_adjust_tmp_values(char **plateau,
			t_filler_tmp *tmp)
{
	while (plateau[tmp.x])
	{
		while (plateau[tmp.x][tmp.y])
		{
			if (plateau[tmp.x][tmp.y] == 'O')
				tmp->has_cap_o++;
			else if (plateau[tmp.x][tmp.y] == 'o')
				tmp->has_o = 1;
			else if (plateau[tmp.x][tmp.y] == 'X')
				tmp->has_cap_x++;
			else if (plateau[tmp.x][tmp.y] == 'x')
				tmp->has_x = 1;
			tmp.y++;
		}
		tmp.x++;
		tmp.y = 0;
	}
}

static void	deduct_game_state_and_ai_token(t_filler_var *v, t_filler_tmp *tmp)
{
	if (!tmp->has_cap_o && !tmp->has_cap_x)
	{
		v->player_token = 'O';
		v->ennemy_token = 'X';
		v->ennemy_token_to_overwrite = 'X';
	}
	else if (tmp->has_cap_o && )
}

void	determine_ai_token(t_filler_var *v, char **plateau)
{
	t_filler_tmp	tmp;

	init_t_filler_tmp(&tmp)
	browse_the_plateau_and_adjust_tmp_values(plateau, &tmp);
	deduct_game_state_and_ai_token(v, &tmp);
}
