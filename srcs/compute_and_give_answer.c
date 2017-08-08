/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_and_give_answer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 12:13:59 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/08 12:10:25 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

/*static void	find_angle_to_handle_token_to_place_and_sort_to_place(t_filler_token
			*start, t_filler_token **to_sort, int target_x, int target_y)
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
		while ((*to_sort)->prev)
			*to_sort = (*to_sort)->prev;
		ptr = *to_sort;
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
	while ((*to_sort->prev)
		*to_sort = (*to_sort)->prev;
}

static int	try_to_place_token(t_filler_token *to_place, t_filler_token
			*placed_tokens, t_filler_var *v)
{
	int	placed;

	placed = 0;
	while (placed < to_place->sum)
	{

	}
}

static int	place_token(t_filler_token *placed_tokens, t_filler_var *v)
{
	while (placed_tokens)
	{
		find_angle_to_handle_token_to_place_and_sort_to_place(placed_tokens,
		&v->to_place, E_COORD_X, E_COORD_Y)
		if (try_to_place_token(v->to_place, placed_tokens))
			return (1);
		placed_tokens = placed_tokens->next;
	}
	return (0);
}*/

int	compute_and_give_answer(t_filler_var *v)
{
	find_enemy_token_position(v);//VALID
	if (v->loop_nb == 1)
		if (!(add_player_first_token_to_placed_tokens_lst(v)))//VALID
			return (0);
	sort_placed_tokens_by_closeness_with_target(&v->placed_tokens, v);//VALID
//	if (!(place_token(v)))
	//	return (0);
	return (1);
}
