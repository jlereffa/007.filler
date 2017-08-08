/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_filler_coord.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:03:55 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/08 13:04:00 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void init_t_filler_coord(t_filler_coord *coord, int x_axis, int y_axis)
{
	c->x_axis = x_axis;
	c->target_is_higher = c.x_axis < 0 ? 0 : 1;
	c->y_axis = y_axis;
	c->target_is_lefter = c.y_axis < 0 ? 0 : 1;
	c->x_abs = c->x_axis < 0 ? c->x_axis * -1 : x->x_axis;
	c->y_abs = c->y_axis < 0 ? c->y_axis * -1 : c->y_axis;
	c->is_x_axis_prio = c->y_abs > c->x_abs ? 0 : 1;
}
