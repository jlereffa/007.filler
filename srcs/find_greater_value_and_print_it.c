/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_greater_value_and_print_it.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nerhak <Nerhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 03:32:29 by Nerhak            #+#    #+#             */
/*   Updated: 2017/08/13 03:54:09 by Nerhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	find_greater_value_and_print_it(t_filler_solution *solution)
{
	t_filler_solution	*ptr;

	//DEB
	if (!solution)
		return ;
	ptr = solution;
	//DEB
	while (solution)
	{
		//DEB
		if (ptr->value < solution->value)
			ptr = solution;
		//DEB
		solution = solution->next;
	}
	//DEB
	/*putf("ptr->x_origin : {");
	ft_putnbr_fd(ptr->x_origin, 2);
	putf("}\nptr->y_origin : {");
	ft_putnbr_fd(ptr->y_origin, 2);
	putf("}\n");
	*/
	ft_putnbr(ptr->x_origin);
	write(1, " ", 1);
	ft_putnbr(ptr->y_origin);
	write(1, "\n", 1);
	//DEB
}
