/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_greater_value_and_print_it.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nerhak <Nerhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 03:32:29 by Nerhak            #+#    #+#             */
/*   Updated: 2017/08/19 09:09:02 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	find_greater_value_and_print_it(
	t_filler_solution *solution, t_filler_var *v)
{
	t_filler_solution	*ptr;

	if (!solution)
		return (0);
	ptr = solution;
	while (solution)
	{
		if (ptr->value < solution->value)
			ptr = solution;
		solution = solution->next;
	}
	ft_putnbr(ptr->x_origin - v->x_token_origin);
	write(1, " ", 1);
	ft_putnbr(ptr->y_origin - v->y_token_origin);
	write(1, "\n", 1);
	return (1);
}
