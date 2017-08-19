/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_token_is_placable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nerhak <Nerhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:54:26 by Nerhak            #+#    #+#             */
/*   Updated: 2017/08/19 09:19:29 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

//
/*
**	I want to stock origin, be it '.' or '*',
**	if the origin is '.', then the first '*' will be 0, 0,
**	the '.' lst taking it's origin just to place it at last
**	then stock every other coord depending of the first '*'
**	if first byte '.', then I skip it for the comparaison.
**	And do everything else normally
*/
//

int	check_if_token_is_placable(t_filler_var *v, int i, int j)
{
	int				overlaps;
	t_filler_token	*tmp;

	overlaps = 0;
	tmp = v->token;
	if (v->map[i][j] == 'P')
		overlaps = 1;
	while (tmp)
	{
		if (i + tmp->x < 0 || i + tmp->x >= v->map_height ||
			(j + tmp->y < 0 || j + tmp->y >= v->map_lenght ||
			v->map[i + tmp->x][j + tmp->y] == 'T' ||
			(v->map[i + tmp->x][j + tmp->y] == 'P' && overlaps)))
			return (0);
		else if (v->map[i + tmp->x][j + tmp->y] == 'P')
			overlaps = 1;
		tmp = tmp->next;
	}
	if (overlaps)
	{
	//	DEB//
		return (1);
	}
//DEB//
	return (0);
}
