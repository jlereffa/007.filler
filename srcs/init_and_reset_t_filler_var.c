/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_reset_t_filler_var.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:10:49 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/12 13:44:51 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	init_and_reset_t_filler_var(t_filler_var *v)
{
	if (!v->is_first_loop)
	{
		del_and_set_to_null_array_table(&v->map);
		del_and_set_to_null_array_table(&v->token_map);
		del_and_set_to_null_t_filler_token(&v->token);
		del_and_set_to_null_t_filler_solution(&v->solution, v->map_height);
	}
	v->map = NULL;
	v->map_height = 0;
	v->map_lenght = 0;
	v->token_map = NULL;
	v->token_map_height = 0;
	v->token_map_lenght = 0;
	v->token = NULL;
	v->solution = NULL;
	//v->is_first_loop = 0;
}
