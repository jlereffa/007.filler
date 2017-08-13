/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_t_filler_solution.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:28:52 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 11:06:48 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	handle_true_prev_and_true_next(t_filler_solution **solution)
{
	(*solution)->next->prev = (*solution)->prev;
	(*solution)->prev->next = (*solution)->next;
	*solution = (*solution)->prev;
}

static void	handle_true_prev_and_false_next(t_filler_solution **solution)
{
	(*solution)->prev->next = NULL;
	*solution = (*solution)->prev;
}

static void	handle_false_prev_and_true_next(t_filler_solution **solution)
{
	(*solution)->next->prev = NULL;
	*solution = (*solution)->next;
}

void	del_and_set_to_null_t_filler_solution(
		t_filler_solution **solution, int i_max)
{
	t_filler_solution	*tmp;

	while (*solution)
	{
		tmp = *solution;
		del_and_set_to_null_int_array_table(&(*solution)->tab, i_max);
		if ((*solution)->prev && (*solution)->next)
			handle_true_prev_and_true_next(solution);
		else if ((*solution)->prev && !(*solution)->next)
			handle_true_prev_and_false_next(solution);
		else if (!(*solution)->prev && (*solution)->next)
			handle_false_prev_and_true_next(solution);
		else
			*solution = NULL;
		free(tmp);
	}
}
