/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_t_filler_solution.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:28:52 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/12 13:46:23 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	del_and_set_to_null_t_filler_solution(
		t_filler_solution **solution, int i_max)
{
	t_filler_solution	*tmp;

	while (*solution)
	{
		tmp = *solution;
		del_and_set_to_null_int_array_table(&(*solution)->tab, i_max);
		if ((*solution)->prev && (*solution)->next)
		{
			(*solution)->next->prev = (*solution)->prev;
			(*solution)->prev->next = (*solution)->next;
			*solution = (*solution)->prev;
		}
		else if ((*solution)->prev && !(*solution)->next)
		{
			(*solution)->prev->next = NULL;
			*solution = (*solution)->prev;
		}
		else if (!(*solution)->prev && (*solution)->next)
		{
			(*solution)->next->prev = NULL;
			*solution = (*solution)->next;
		}
		else
			*solution = NULL;
		free(tmp);
	}
}
