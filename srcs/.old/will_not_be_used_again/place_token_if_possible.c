/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token_if_possible.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 12:25:51 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/09 17:45:52 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static t_filler_token	*format_current_token(t_filler_token *token)
{
	int	x;
	int	y;
	t_filler_token	*new_token;
	t_filler_token	*tmp;

	x = token->x;
	y = token->y;
	new_token = NULL;
	/*if (!(new_token = set_t_filler_token(new_token, x, y)))
		return (0);*/
	while (token->prev)
		token = token->prev;
	while (token)
	{
		if ((token->x != x || token->y != y) &&
			(!(new_token = set_t_filler_token(new_token, token->x - x,
			token->y - y))))
			return (0);
		token = token->next;
	}
	while (new_token->prev)
		new_token = new_token->prev;
	ft_putstr_fd("\033[1;33mCHECK : format_current_token | LINE 39\n\033[0m", 2);
	tmp = new_token;
	while (tmp)
	{
		ft_putstr_fd("formated piece : \n", 2);
		ft_putstr_fd("tmp->x : {", 2);
		ft_putnbr_fd(tmp->x, 2);
		ft_putstr_fd("}\ntmp->y : {", 2);
		ft_putnbr_fd(tmp->y, 2);
		ft_putstr_fd("}\n", 2);
		tmp = tmp->next;
	}
	return (new_token);
}

static int				try_to_fit_on_plateau(t_filler_token *placed,
						t_filler_token *token, t_filler_var *v)
{
	token = token->next;
	while (token)
	{
		if (placed->x + token->x >= 0 &&
			placed->x + token->x < v->plateau_height &&
			placed->y + token->y >= 0 &&
			placed->y + token->y < v->plateau_height)
		{
			if (v->plateau[placed->x + token->x][placed->y + token->y] != '.')
				return (0);
		}
		else
			return (0);
		token = token->next;
	}
	return (1);
}

static int				add_placed_token_to_placed_tokens_lst(t_filler_token
						*to_add, t_filler_token *token_lst)
{
	int	x;
	int	y;
	t_filler_token	*tmp;//TO DEL

	x = token_lst->x;
	y = token_lst->y;
	to_add = to_add->next;
	tmp = token_lst;
	while (to_add)
	{
		if (!(token_lst = set_t_filler_token(token_lst, x + to_add->x,
			y + to_add->y)))
			return (0);
		to_add = to_add->next;
	}
	ft_putstr_fd("\033[1;33mCHECK : add_placed_token_to_placed_tokens_lst | LINE 81\n\033[0m", 2);
	while (tmp)
	{
		ft_putstr_fd("new tokens : \n", 2);
		ft_putstr_fd("tmp->x : {", 2);
		ft_putnbr_fd(tmp->x, 2);
		ft_putstr_fd("}\ntmp->y : {", 2);
		ft_putnbr_fd(tmp->y, 2);
		ft_putstr_fd("}\n", 2);
		tmp = tmp->next;
	}
	ft_putstr_fd("------------\n", 2);
	return (1);
}

static int				try_to_place_token(t_filler_token *to_place,
						t_filler_token *placed_tokens, t_filler_var *v)
{
	t_filler_token	*tmp;
	t_filler_token	*tmp2;

	while (to_place)
	{
		if (!(tmp = format_current_token(to_place)))
			return (0);
		ft_putstr_fd("\033[1;33mCHECK : try_to_place_token | LINE 117\n\033[0m", 2);
		tmp2 = tmp;
		while (tmp2)
		{
			ft_putstr_fd("formated piece : \n", 2);
			ft_putstr_fd("tmp2->x : {", 2);
			ft_putnbr_fd(tmp2->x, 2);
			ft_putstr_fd("}\ntmp2->y : {", 2);
			ft_putnbr_fd(tmp2->y, 2);
			ft_putstr_fd("}\n", 2);
			tmp2 = tmp2->next;
		}
		if (try_to_fit_on_plateau(placed_tokens, tmp, v))
		{
			if (!(add_placed_token_to_placed_tokens_lst(tmp, placed_tokens)))
				return (0);
			ft_putstr_fd("tmp->x : {", 2);
			ft_putnbr_fd(tmp->x, 2);
			ft_putstr_fd("}\ntmp->y : {", 2);
			ft_putnbr_fd(tmp->y, 2);
			ft_putstr_fd("}\n", 2);
			ft_putstr_fd("placed_tokens->x : {", 2);
			ft_putnbr_fd(placed_tokens->x, 2);
			ft_putstr_fd("}\nplaced_tokens->y : {", 2);
			ft_putnbr_fd(placed_tokens->y, 2);
			ft_putstr_fd("}\n", 2);
			ft_putnbr(placed_tokens->x - tmp->x);
			ft_putstr(" ");
			ft_putnbr(placed_tokens->y - tmp->y);
			ft_putstr("\n");
			return (1);
		}
		to_place = to_place->next;
	}
	return (0);
}

int			place_token_if_possible(t_filler_token *placed_tokens, t_filler_var *v)
{
	while (placed_tokens)
	{
		find_angle_to_handle_token_to_place_and_sort(placed_tokens,
		&v->to_place, E_COORD_X, E_COORD_Y);
		if (try_to_place_token(v->to_place, placed_tokens, v))
			return (1);
		placed_tokens = placed_tokens->next;
	}
	return (0);
}
