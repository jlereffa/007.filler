/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_t_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 16:31:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/31 17:48:23 by jlereffa         ###   ########.fr       */
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
		t_piece->prev = NULL;
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
				write(3, "Point : ", 8);
				write(3, "x{", 2);
				ft_putnbr_fd(t_piece->x, 3);
				write(3, "} y{", 4);
				ft_putnbr_fd(t_piece->y, 3);
				write(3, "}\n", 2);
			}
			y++;
		}
		x++;
		y = 0;
	}
	while (t_piece->prev)
		t_piece = t_piece->prev;
	return (t_piece);
}
