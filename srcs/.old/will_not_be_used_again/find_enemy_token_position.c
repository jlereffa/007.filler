/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_enemy_token_position.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 11:51:47 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/08 11:52:00 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	find_enemy_token_position(t_filler_var *v)//VALID
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
	//TO DEL
	ft_putstr_fd("enemy x coord : {", 2);
	ft_putnbr_fd(v->enemy_token_to_chase_coord_x, 2);
	ft_putstr_fd("}\nenemy y coord : {", 2);
	ft_putnbr_fd(v->enemy_token_to_chase_coord_y, 2);
	ft_putstr_fd("}\n", 2);
}
