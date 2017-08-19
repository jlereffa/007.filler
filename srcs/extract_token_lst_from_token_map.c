/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token_lst_from_token_map.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 09:40:07 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 09:35:46 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	set_origin_coordinates(t_filler_var *v, int i, int j)
{
	v->x_token_origin = i;
	v->y_token_origin = j;
}

int			extract_token_lst_from_token_map(t_filler_var *v)
{
	int	i;
	int	j;
	int	is_origin_point;

	i = -1;
	is_origin_point = 1;
	while (v->token_map[++i])
	{
		j = -1;
		while (v->token_map[i][++j])
		{
			if (v->token_map[i][j] == '*' && is_origin_point &&
				!(is_origin_point = 0))
				set_origin_coordinates(v, i, j);
			else if (v->token_map[i][j] == '*' &&
				!(v->token = set_t_filler_token(
				v->token, i - v->x_token_origin, j - v->y_token_origin)))
				return (0);
		}
	}
	return (!rewind_t_filler_token(&v->token) ? 0 : 1);
}
