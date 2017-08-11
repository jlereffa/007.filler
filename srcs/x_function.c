/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_function.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 10:39:59 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/11 11:20:29 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	check_if_token_is_placable(t_filler_var *v, int i, int j)
{
	int				overlaps;
	t_filler_token	*tmp;

	overlaps = 0;
	tmp = v->token;
	while (tmp)
	{
		if (i + v->token->x < 0 || i + v->token->x >= v->map_height ||
			(j + v->token->y < 0 || j + v->token->y >= v->map_lenght ||
			v->map[i + v->token->x][j + v->token->y] == 'T' ||
			(v->map[i + v->token->x][j + v->token->y] == 'P' && overlaps)))
			return (0);
		else if (v->map[i + v->token->x][j + v->token->y] == 'P')
			overlaps = 1;
		tmp = tmp->next;
	}
	return (1);
}

int	evaluate_and_stock_solution(t_filler_var *v, int i, int j)
{
	t_filler_token	*tmp;

	if (!(v->solution = set_t_filler_solution(v->solution, v)))
		return (0);
}

int	placeholder_name_1_function(t_filler_var *v)
{
	int	i;
	int	j;

	i = -1;
	while (v->map[++i])
	{
		j = -1;
		while (v->map[i][++j])
		{
			if (v->map[i][j] != 'T')
			{
				if (check_if_token_is_placable(v, i, j))
				{
					if (!evaluate_and_stock_solution(v, i, j))
				}
			}
		}

	}
}
