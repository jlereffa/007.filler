/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_token_is_placable.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nerhak <Nerhak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 16:54:26 by Nerhak            #+#    #+#             */
/*   Updated: 2017/08/12 14:20:08 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	check_if_token_is_placable(t_filler_var *v, int i, int j)
{
	int				overlaps;
	t_filler_token	*tmp;

	overlaps = 0;
	tmp = v->token;
	DEB
	while (tmp)
	{
		DEB
		if (i + v->token->x < 0 || i + v->token->x >= v->map_height ||
			(j + v->token->y < 0 || j + v->token->y >= v->map_lenght ||
			v->map[i + v->token->x][j + v->token->y] == 'T' ||
			(v->map[i + v->token->x][j + v->token->y] == 'P' && overlaps)))
			return (0);
		else if (v->map[i + v->token->x][j + v->token->y] == 'P')
			overlaps = 1;
		tmp = tmp->next;
	}
	if (overlaps == 1)
		return (1);
	DEB
	return (0);
}
