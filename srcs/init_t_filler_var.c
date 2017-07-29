/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_filler_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 17:01:58 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/29 17:25:06 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	init_t_filler_var(t_filler_var *v)
{
	v->map = NULL;
	v->map_height = 0;
	v->map_lenght = 0;
	v->piece = NULL;
	v->piece_height = 0;
	v->piece_lenght = 0;
	v->t_piece = NULL;
}
