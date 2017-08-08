/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_angle_to_handle_token_to_place_and_sort.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:06:41 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/08 13:07:24 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	switch_tokens_positions(int *sorted, t_filler_token **ptr)
{
	t_filler_token *tmp;

	*sorted = 0;
	if ((*ptr)->prev)
		(*ptr)->prev->next = (*ptr)->next;
	(*ptr)->next->prev = (*ptr)->prev;
	tmp = (*ptr)->next->next;
	(*ptr)->next->next = *ptr;
	(*ptr)->prev = (*ptr)->next;
	(*ptr)->next = tmp;
}

static int	check_if_switch_condition_met(t_filler_token *ptr,
			t_filler_coord *c)
{
	if (ptr->next && c->is_x_axis_prio && c->target_is_higher &&
		((ptr->x < ptr->next->x) ||
		(ptr->x == ptr->next->x &&
		((c->target_is_lefter && ptr->y < ptr->next->y) ||
		(!c->target_is_lefter && ptr->y > ptr->next->y)))))
		return (1);
	else if (ptr->next && is_x_axis_prio && !target_is_higher &&
			((ptr->x > ptr->next->x) ||
			(ptr->x == ptr->next->x &&
			((c->target_is_lefter && ptr->y < ptr->next->y) ||
			(!c->target_is_lefter && ptr->y > ptr->next->y)))))
		return (1);
	else if (ptr->next && !is_x_axis_prio && c->target_is_lefter &&
			((ptr->y < ptr->next->y) ||
			(ptr->y == ptr->next->y &&
			((c->target_is_higher && ptr->x < ptr->next->x) ||
			(!c->target_is_higher && ptr->x > ptr->next->x)))))
		return (1);
	else if (ptr->next && !is_x_axis_prio && !c->target_is_lefter &&
			((ptr->y > ptr->next->y) ||
			(ptr->y == ptr->next->y &&
			((c->target_is_higher && ptr->x < ptr->next->x) ||
			(!c->target_is_higher && ptr->x > ptr->next->x)))))
		return (1);
	return (0);
}

void		find_angle_to_handle_token_to_place_and_sort(t_filler_token *start,
			t_filler_token **to_sort, int target_x, int target_y)
{
	int				sorted;
	int				sum;
	t_filler_coord	coord;
	t_filler_token	*ptr;
	t_filler_token	*tmp;//TO DEL

	init_t_filler_coord(&coord, start->x - target_x, start->y - target_y);
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		sum = 0;
		while ((*to_sort)->prev)
			*to_sort = (*to_sort)->prev;
		ptr = *to_sort;
		while (sum < ptr->sum)
		{
			if (check_if_switch_condition_met(ptr, &coord))
				switch_tokens_positions(&sorted, &ptr);
			sum++;
			ptr = ptr->next;
		}
	}
	while ((*to_sort->prev)
		*to_sort = (*to_sort)->prev;
	tmp = *to_sort;//TO DEL
	while (tmp)//TO DEL
	{

		tmp = tmp->next
	}
}
