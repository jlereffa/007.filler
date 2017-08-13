/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind_t_filler_solution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:31:31 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 03:44:55 by Nerhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	rewind_t_filler_solution(t_filler_solution **solution)
{
	if (solution && *solution)
		while ((*solution)->prev)
			*solution = (*solution)->prev;
}
