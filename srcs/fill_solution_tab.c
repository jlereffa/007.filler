/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_solution_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 10:35:12 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 11:01:57 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	check_square_and_fill_if_needed(
		int ***tab, int *i_tab, int value, t_filler_var *v)
{
	int	i_mod;
	int	j_mod;
	int	mod_1;
	int	mod_2;

	i_mod = -2;
	mod_1 = value >= 0 ? 1 : -1;
	mod_2 = value >= 0 ? -1 : 1;
	while (++i_mod < 2)
	{
		j_mod = -2;
		while (++j_mod < 2)
		{
			if (i_tab[0] + i_mod >= 0 && i_tab[1] + j_mod >= 0 &&
				i_tab[0] + i_mod < v->map_height &&
				i_tab[1] + j_mod < v->map_lenght)
			{
				if ((*tab)[i_tab[0] + i_mod][i_tab[1] + j_mod] == 255)
					(*tab)[i_tab[0] + i_mod][i_tab[1] + j_mod] = value + mod_1;
				else if ((*tab)[i_tab[0] + i_mod][i_tab[1] + j_mod] ==
						-value - mod_2)
					(*tab)[i_tab[0] + i_mod][i_tab[1] + j_mod] = 0;
			}
		}
	}
}

void	fill_solution_tab(int ***tab, t_filler_var *v)
{
	int	i_tab[2];
	int	value;
	int	done;

	done = 0;
	value = 1;
	while (!done)
	{
		done = 1;
		i_tab[0] = -1;
		while (++i_tab[0] < v->map_height)
		{
			i_tab[1] = -1;
			while (++i_tab[1] < v->map_lenght)
			{
				if ((*tab)[i_tab[0]][i_tab[1]] == value && !(done = 0))
					check_square_and_fill_if_needed(tab, i_tab, value, v);
				else if ((*tab)[i_tab[0]][i_tab[1]] == -value && !(done = 0))
					check_square_and_fill_if_needed(tab, i_tab, -value, v);
			}
		}
		value++;
	}
}
