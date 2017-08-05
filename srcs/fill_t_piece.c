/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_t_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 16:31:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 12:01:54 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static t_filler_piece	*handle_t_piece_lst(t_filler_piece *t_piece, int x,
						int y)
{
	if (!t_piece)
	{
		if (!(t_piece = (t_filler_piece*)malloc(sizeof(t_filler_piece))))
			return (NULL);
		t_piece->x = x;
		t_piece->y = y;
		t_piece->prev = NULL;
		t_piece->next = NULL;
		return (t_piece);
	}
	while (t_piece->next)
		t_piece = t_piece->next;
	if (!(t_piece->next = handle_t_piece_lst(t_piece->next, x, y)))
		return (NULL);
	t_piece->next->prev = t_piece;
	t_piece = t_piece->next;
	return (t_piece);
}

t_filler_piece			*fill_t_piece(char **piece, t_filler_piece *t_piece)
{
	int	x;
	int	y;
	t_filler_piece *tmp;//TO DEL

	x = 0;
	y = 0;
	while (piece[x])
	{
		while (piece[x][y])
		{
			if (piece[x][y] == '*')
			{
				if (!(t_piece = handle_t_piece_lst(t_piece, x, y)))
					return (NULL);
			}
			y++;
		}
		x++;
		y = 0;
	}
	while (t_piece->prev)
		t_piece = t_piece->prev;
	tmp = t_piece;//TO DELL
	while (tmp)//TO DEL
	{
		ft_putstr_fd("piece : x{", 2);
		ft_putnbr_fd(tmp->x, 2);
		ft_putstr_fd("} y{", 2);
		ft_putnbr_fd(tmp->y, 2);
		ft_putendl_fd("}", 2);
		tmp = tmp->next;
	}
	return (t_piece);
}
