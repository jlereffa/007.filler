/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_and_stock_solution.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nerhak <Nerhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:38:14 by Nerhak            #+#    #+#             */
/*   Updated: 2017/08/18 12:28:33 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	evaluate_and_stock_solution(t_filler_var *v, int i, int j)
{
	if (!(v->solution = set_t_filler_solution(v->solution, v, i, j)))
		return (0);
	return (1);
}
