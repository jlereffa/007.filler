/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_and_give_answer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 12:13:59 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/06 19:32:37 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int	add_first_token_to_placed_tokens_lst(t_filler_var *v)
{
	int	i;
	int	j;
	t_filler_token	*tmp;//TO DEL

	i = 0;
	j = 0;
	while (v->plateau[i] && !v->player_token_is_found)
	{
		while (v->plateau[i][j] && !v->player_token_is_found)
		{
			if (v->plateau[i][j] == v->player_token)
			{
DEB
				if (!(v->placed_tokens = set_t_filler_token(v->placed_tokens,
					i, j)))
					return (0);
				v->player_token_is_found = 1;
				tmp = v->placed_tokens;//TO DEL
			}
			j++;
		}
		i++;
		j = 0;
	}
	while (tmp)//TO DEL
	{
		ft_putstr_fd("placed_token : x{", 2);
		ft_putnbr_fd(tmp->x, 2);
		ft_putstr_fd("} y{", 2);
		ft_putnbr_fd(tmp->y, 2);
		ft_putendl_fd("}", 2);
		tmp = tmp->next;
	}
	return (1);
}

static void	find_enemy_token_position(t_filler_var *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (v->plateau[i] && !v->enemy_token_is_found)
	{
		while (v->plateau[i][j] && !v->enemy_token_is_found)
		{
			if (v->plateau[i][j] == v->enemy_token_to_chase)
			{
				E_COORD_X = i;
				E_COORD_Y = j;
				v->enemy_token_is_found = 1;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

static void	establish_closeness(t_filler_token *token, int x, int y)
{
	int	ret_x;
	int	ret_y;

	while (token)
	{
		ret_x = (x - token->x) < 0 ? (x - token->x) * -1 : x - token->x;
		ret_y = (y - token->y) < 0 ? (y - token->y) * -1 : y - token->y;
		token->closeness = ret_x + ret_y;
		token = token->next;
	}
}

static void	sort_placed_tokens_by_closeness_with_target(t_filler_token **token,
			t_filler_var *v)
{
	int				sorted;
	t_filler_token	*tmp;
	t_filler_token	*ptr;

	sorted = 0;
	establish_closeness(*token, E_COORD_X, E_COORD_Y);
	while (!sorted)
	{
		sorted = 1;
		ptr = *token;
		while (ptr)
		{
			if (ptr->next && ptr->closeness > ptr->next->closeness)
			{
				sorted = 0;
				if (ptr->prev)
					ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				tmp = ptr->next->next;
				ptr->next->next = ptr;
				ptr->prev = ptr->next;
				ptr->next = tmp;
			}
			ptr = ptr->next;
		}
	}
	while ((*token)->prev)
		*token = (*token)->prev;
}

static void	find_angle_to_handle_token_to_place_and_sort_to_place(t_filler_token
			*start, t_filler_token *to_sort, int target_x, int target_y)
{
	int x_axis;//<- Define if target is upper or lower than point
	int x_abs;//<- Define if target is more to the left or to the right than point
	int	y_axis;//<- Define the distance in x_axis in brut
	int	y_abs;//<- Define the distance in y_axis in brut
	int	is_x_axis_prio;//<- define if the distance in height is greater than in y_axis
	int	target_is_higher;//<- if target is higher, place prio greater values
	int	target_is_lefter;//<- if target is lefter, place prio greater values
	int	sorted;
	t_filler_token	*ptr;
	t_filler_token	*tmp;

	x_axis = start->x - target_x;
	target_is_higher = x_axis < 0 ? 0 : 1;
	y_axis = start->y - target_y;
	target_is_lefter = y_axis < 0 ? 0 : 1;
	x_abs = x_axis < 0 ? x_axis * -1 : x_axis;
	y_abs = y_axis < 0 ? y_axis * -1 : y_axis;
	is_x_axis_prio = y_abs > x_abs ? 0 : 1;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		ptr = to_sort;
		while (ptr)
		{
			if (ptr->next && is_x_axis_prio && target_is_higher &&
				((to_sort->x < to_sort->next->x) ||
				(to_sort->x == to_sort->next->x &&
				((target_is_lefter && to_sort->y < to_sort->next->y) ||
				(!target_is_lefter && to_sort->y > to_sort->next->y)))))
			{
				sorted = 0;
				if (ptr->prev)
					ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				tmp = ptr->next->next;
				ptr->next->next = ptr;
				ptr->prev = ptr->next;
				ptr->next = tmp;
			}
			else if (ptr->next && is_x_axis_prio && !target_is_higher &&
					((to_sort->x > to_sort->next->x) ||
					(to_sort->x == to_sort->next->x &&
					((target_is_lefter && to_sort->y < to_sort->next->y) ||
					(!target_is_lefter && to_sort->y > to_sort->next->y)))))
			{
				sorted = 0;
				if (ptr->prev)
					ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				tmp = ptr->next->next;
				ptr->next->next = ptr;
				ptr->prev = ptr->next;
				ptr->next = tmp;
			}
			else if (ptr->next && !is_x_axis_prio && target_is_lefter &&
					((to_sort->y < to_sort->next->y) ||
					(to_sort->y == to_sort->next->y &&
					((target_is_higher && to_sort->x < to_sort->next->x) ||
					(!target_is_higher && to_sort->x > to_sort->next->x)))))
			{
				sorted = 0;
				if (ptr->prev)
					ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				tmp = ptr->next->next;
				ptr->next->next = ptr;
				ptr->prev = ptr->next;
				ptr->next = tmp;
			}
			else if (ptr->next && !is_x_axis_prio && !target_is_lefter &&
					((to_sort->y > to_sort->next->y) ||
					(to_sort->y == to_sort->next->y &&
					((target_is_higher && to_sort->x < to_sort->next->x) ||
					(!target_is_higher && to_sort->x > to_sort->next->x)))))
			{
				sorted = 0;
				if (ptr->prev)
					ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				tmp = ptr->next->next;
				ptr->next->next = ptr;
				ptr->prev = ptr->next;
				ptr->next = tmp;
			}
			ptr = ptr->next;
		}
	}
}

static int	place_token(t_filler_token *placed_tokens, t_filler_var *v)
{
	while (placed_tokens)
	{
		find_angle_to_handle_token_to_place_and_sort_to_place(placed_tokens,
		v->to_place, E_COORD_X, E_COORD_Y)
		if (try_to_fit_token(v->to_place, placed_tokens))
			return (1);
		placed_tokens = placed_tokens->next;
	}
	return (0);
}

int	compute_and_give_answer(t_filler_var *v)
{
DEB
	find_enemy_token_position(v);
DEB
	if (v->loop_nb == 1)
	{
DEB
		if (!(add_first_token_to_placed_tokens_lst(v->placed_tokens)))
			return (0);
	}
DEB
	sort_placed_tokens_by_closeness_with_target(v->placed_tokens, v);
	if (!(place_token(v)))
		return (0);
DEB
	return (1);
}
