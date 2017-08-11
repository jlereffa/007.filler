/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token_lst_from_token_map.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 09:40:07 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/11 10:09:42 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	extract_token_lst_from_token_map(t_filler_var *v)
{
	int	i;
	int	j;
	int	x_origin;
	int	y_origin;
	int	is_origin_point;

	i = 0;
	is_origin_point = 1;
	while (v->token_map[i])
	{
		j = 0;
		while (v->token_map[i][j])
		{
			if (v->token_map[i][j] == '*')
			{
				if (is_origin_point)
				{
					x_origin = i;
					y_origin = j;
					is_origin_point = 0;
				}
				if (!(v->token = set_t_filler_token(
					v->token, i - x_origin, j - y_origin)))
					return (0);
			}
			j++;
		}
		i++;
	}
	while (v->token->prev)
		v->token = v->token->prev;
	return (1);
}
