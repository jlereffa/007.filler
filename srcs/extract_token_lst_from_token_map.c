/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token_lst_from_token_map.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 09:40:07 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 10:27:14 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	set_origin_coordinates(int *x_origin, int *y_origin, int i, int j)
{
	*x_origin = i;
	*y_origin = j;
}

int			extract_token_lst_from_token_map(t_filler_var *v)
{
	int	i;
	int	j;
	int	x_origin;
	int	y_origin;
	int	is_origin_point;

	i = -1;
	is_origin_point = 1;
	while (v->token_map[++i])
	{
		j = -1;
		while (v->token_map[i][++j])
		{
			if (v->token_map[i][j] == '*')
			{
				if (is_origin_point && !(is_origin_point = 0))
					set_origin_coordinates(&x_origin, &y_origin, i, j);
				if (!(v->token = set_t_filler_token(
					v->token, i - x_origin, j - y_origin)))
					return (0);
			}
		}
	}
	return (!rewind_t_filler_token(&v->token) ? 0 : 1);
}
