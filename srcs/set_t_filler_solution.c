/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t_filler_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 11:20:45 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/11 11:48:45 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int			initialize_solution_tab(int ***tab, t_filler_var *v)
{
	int	i;
	int	j;

	i = -1;
	if (!(*tab = (int**)malloc(sizeof(int*) * v->map_height)))
		return (0);
	while (++i < v->map_height)
	{
		if (!(*tab[i] = (int*)malloc(sizeof(int) * v->map_lenght)))
			return (0);
		j = -1;
		while (++j < v->map_lenght)
		{
			if (v->map[i][j] == '.')
				tab[i][j] = 0;
			else if (v->map[i][j] == 'P')
				tab[i][j] = 1;
			else if (v->map[i][j] == 'T')
				tab[i][j] = -1;
		}
	}
	
}

t_filler_solution	*set_t_filler_solution(
					t_filler_solution *solution, t_filler_var *v)
{
	if (!solution)
	{
		if (!(solution = (t_filler_solution*)malloc(sizeof(t_filler_solution))))
			return (NULL);
		solution->value = 0;
		if (!(initialize_solution_tab(&solution->tab, v)))
			return (NULL);
		solution->prev = NULL;
		solution->next = NULL;
		return (solution);
	}

}
