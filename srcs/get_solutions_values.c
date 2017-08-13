/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_solutions_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:15:07 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 10:35:29 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int	count_solution_points_value(int **tab, t_filler_var *v)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = -1;
	while (++i < v->map_height)
	{
		j = -1;
		while (++j < v->map_lenght)
			ret += tab[i][j];
	}
	return (ret);
}

int			get_solutions_values(t_filler_solution *solution, t_filler_var *v)
{
	if (!solution)
		return (0);
	while (solution)
	{
		fill_solution_tab(&solution->tab, v);
		solution->value = count_solution_points_value(solution->tab, v);
		solution = solution->next;
	}
	return (1);
}
