/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token_lst_from_token_map.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 09:40:07 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/19 09:22:34 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

//I want to remember and the origin points, and the shape origin points.
//Please, do this.

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
	t_filler_token	*tmp;//

	tmp = v->token;
	/*sleep(1);
	putf("____NEW_TOKEN____\n");
	putf("token->origin : x{");
	ft_putnbr_fd(v->x_token_origin, 2);
	putf("} | token->origin : y{");
	ft_putnbr_fd(v->y_token_origin, 2);
	putf("}\n");
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		putf("token->x {");
		ft_putnbr_fd(tmp->x, 2);
		putf("} | token->y {");
		ft_putnbr_fd(tmp->y, 2);
		putf("}\n");
		tmp = tmp->next;
	}
	putf("____END_TOKEN____\n");
	*/return (!rewind_t_filler_token(&v->token) ? 0 : 1);
}
