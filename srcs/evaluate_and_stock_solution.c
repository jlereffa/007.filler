/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_and_stock_solution.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nerhak <Nerhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:38:14 by Nerhak            #+#    #+#             */
/*   Updated: 2017/08/11 17:06:23 by Nerhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	evaluate_and_stock_solution(t_filler_var *v, int i, int j)
{
	t_filler_token	*tmp;

	if (!(v->solution = set_t_filler_solution(v->solution, v)))
		return (0);
	
}
