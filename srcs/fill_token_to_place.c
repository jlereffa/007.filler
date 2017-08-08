/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_token_to_place.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 16:31:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/07 18:24:39 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

t_filler_token	*fill_token_to_place(char **token_map,
				t_filler_token *to_place)
{
	int	x;
	int	y;
	int	sum;
	t_filler_token *tmp;//TO DEL
	int	i;//TO DELL
	t_filler_token *ptr;

	x = 0;
	y = 0;
	sum = 0;
	while (token_map[x])
	{
		while (token_map[x][y])
		{
			if (token_map[x][y] == '*')
			{
				if (!(to_place = set_t_filler_token(to_place, x, y)))
					return (NULL);
				sum++;
			}
			y++;
		}
		x++;
		y = 0;
	}
	while (to_place->prev)
		to_place = to_place->prev;
	ptr = to_place;
	while (ptr->next)
	{
		ptr->sum = sum;
		ptr = ptr->next;
	}
	ptr->sum = sum;
	ptr->next = to_place;
	to_place->prev = ptr;
	tmp = to_place;//TO DELL
	i = 0;
	while (i < sum)//TO DEL
	{
		ft_putstr_fd("piece : x{", 2);
		ft_putnbr_fd(tmp->x, 2);
		ft_putstr_fd("} y{", 2);
		ft_putnbr_fd(tmp->y, 2);
		ft_putendl_fd("}", 2);
		ft_putstr_fd("sum : {", 2);
		ft_putnbr_fd(tmp->sum, 2);
		ft_putendl_fd("}", 2);
		tmp = tmp->next;
		i++;
	}
	return (to_place);
}
