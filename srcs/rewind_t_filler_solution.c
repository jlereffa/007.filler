/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewind_t_filler_solution.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:31:31 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 10:26:02 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	rewind_t_filler_solution(t_filler_solution **solution)
{
	if (!solution || !*solution)
		return (0);
	while ((*solution)->prev)
		*solution = (*solution)->prev;
	return (1);
}
