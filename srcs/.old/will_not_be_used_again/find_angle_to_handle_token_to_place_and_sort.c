/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_angle_to_handle_token_to_place_and_sort.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:06:41 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/08 16:56:40 by jlereffa         ###   ########.fr       */
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
	//static int	i;

	if (ptr->next && c->is_x_axis_prio && c->target_is_higher &&
		((ptr->x < ptr->next->x) ||
		(ptr->x == ptr->next->x &&
		((c->target_is_lefter && ptr->y < ptr->next->y) ||
		(!c->target_is_lefter && ptr->y > ptr->next->y)))))
	{
		DEB
		return (1);
	}
	else if (ptr->next && c->is_x_axis_prio && !c->target_is_higher &&
			((ptr->x > ptr->next->x) ||
			(ptr->x == ptr->next->x &&
			((c->target_is_lefter && ptr->y < ptr->next->y) ||
			(!c->target_is_lefter && ptr->y > ptr->next->y)))))
	{
		DEB
		return (1);
	}
	else if (ptr->next && !c->is_x_axis_prio && c->target_is_lefter &&
			((ptr->y < ptr->next->y) ||
			(ptr->y == ptr->next->y &&
			((c->target_is_higher && ptr->x < ptr->next->x) ||
			(!c->target_is_higher && ptr->x > ptr->next->x)))))
	{
		DEB
		return (1);
	}
	else if (ptr->next && !c->is_x_axis_prio && !c->target_is_lefter &&
			((ptr->y > ptr->next->y) ||
			(ptr->y == ptr->next->y &&
			((c->target_is_higher && ptr->x < ptr->next->x) ||
			(!c->target_is_higher && ptr->x > ptr->next->x)))))
	{
		/*if (i == 0)
		{
			ft_putstr_fd("\n\033[1;33m--------------------------------\033[0m\n", 2);
			ft_putstr_fd("c->is_x_axis_prio : ", 2);
			ft_putnbr_fd(c->is_x_axis_prio, 2);
			ft_putstr_fd("\nc->target_is_higher : ", 2);
			ft_putnbr_fd(c->target_is_higher, 2);
			ft_putstr_fd("\nc->target_is_lefter : ", 2);
			ft_putnbr_fd(c->target_is_lefter, 2);
			ft_putstr_fd("\nptr->x : ", 2);
			ft_putnbr_fd(ptr->x, 2);
			ft_putstr_fd("\nptr->next->x : ", 2);
			ft_putnbr_fd(ptr->next->x, 2);
			ft_putstr_fd("\nptr->y : ", 2);
			ft_putnbr_fd(ptr->y, 2);
			ft_putstr_fd("\nptr->next->y : ", 2);
			ft_putnbr_fd(ptr->next->y, 2);
			ft_putstr_fd("\nptr->x : ", 2);
			ft_putnbr_fd(ptr->x, 2);
			ft_putstr_fd("\nptr->next->x : ", 2);
			ft_putnbr_fd(ptr->next->x, 2);
			ft_putstr_fd("\n", 2);
			exit(0);
		}
		i = 1;*/
		return (1);
	}
	return (0);
}

void		find_angle_to_handle_token_to_place_and_sort(t_filler_token *start,
			t_filler_token **to_sort, int target_x, int target_y)
{
	int				sorted;
	t_filler_coord	coord;
	t_filler_token	*ptr;
	t_filler_token	*tmp;//TO DEL

	init_t_filler_coord(&coord, start->x - target_x, start->y - target_y);
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		while ((*to_sort)->prev)
			*to_sort = (*to_sort)->prev;
		ptr = *to_sort;
		while (ptr)
		{
			if (check_if_switch_condition_met(ptr, &coord))
			{
				ft_putendl_fd("Needs to be switch", 2);
				switch_tokens_positions(&sorted, &ptr);
			}
			ptr = ptr->next;
		}
	}
	DEB
	while ((*to_sort)->prev)
		*to_sort = (*to_sort)->prev;
	tmp = *to_sort;//TO DEL
	while (tmp)//TO DEL
	{
		ft_putstr_fd("Point : x{", 2);
		ft_putnbr_fd(tmp->x, 2);
		ft_putstr_fd("} y {", 2);
		ft_putnbr_fd(tmp->y, 2);
		ft_putstr_fd("}\n", 2);
		tmp = tmp->next;
	}
}
