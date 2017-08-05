/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_if_1_player_game.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 20:40:40 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 20:40:54 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	find_if_1_player_game(t_filler_var *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (v->plateau[i])
	{
		while (v->plateau[i][j])
		{
			if (v->plateau == 'x')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
