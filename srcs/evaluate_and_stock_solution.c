/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_and_stock_solution.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nerhak <Nerhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:38:14 by Nerhak            #+#    #+#             */
/*   Updated: 2017/08/13 03:44:46 by Nerhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	evaluate_and_stock_solution(t_filler_var *v, int i, int j)
{
	//t_filler_solution	*tmp;
	//DEB
	if (!(v->solution = set_t_filler_solution(v->solution, v, i, j)))
		return (0);
	rewind_t_filler_solution(&v->solution);
	get_solutions_values(v->solution, v);
	find_greater_value_and_print_it(v->solution);
//	DEB
	return (1);
}
