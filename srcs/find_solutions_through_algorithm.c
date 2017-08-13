/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solutions_through_algorithm.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:39:59 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 13:08:21 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	find_solutions_through_algorithm(t_filler_var *v)
{
	int	i;
	int	j;

	i = -1;
	while (v->map[++i])
	{
		j = -1;
		while (v->map[i][++j])
		{
			if (v->map[i][j] != 'T' && check_if_token_is_placable(v, i, j) &&
				!evaluate_and_stock_solution(v, i, j))
			{
				putf("FAIS PAS LE CON PHILIPPE !\n");
				return (0);
			}
		}
	}
	if (!rewind_t_filler_solution(&v->solution))
	{
		putf("TEST ?\n");
		return (0);
	}
	putf("ET LA ?\n");
	return (1);
}
