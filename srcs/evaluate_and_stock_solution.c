/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_and_stock_solution.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nerhak <Nerhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:38:14 by Nerhak            #+#    #+#             */
/*   Updated: 2017/08/18 11:37:43 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	evaluate_and_stock_solution(t_filler_var *v, int i, int j)
{
	if (!(v->solution = set_t_filler_solution(v->solution, v, i, j)))
	{
		DEB
		return (0);
	}
	v->solution_found = 1;
	if (!(rewind_t_filler_solution(&v->solution)))
	{
		DEB
		return (0);
	}
	if (!(get_solutions_values(v->solution, v)))
	{
		DEB
		return (0);
	}
	if (!find_greater_value_and_print_it(v->solution))
	{
		DEB
		return (0);
	}
	return (1);
}
