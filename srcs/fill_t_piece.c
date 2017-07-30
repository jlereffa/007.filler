/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_t_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 16:31:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/30 17:25:01 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

//
void	deb(char *s)
{
	write(3, "DEBUG : ", 8);
	while (*s)
	{
		write(3, s, 1);
		s++;
	}
	write(3, "\n", 1);
}
//


static t_filler_piece	*handle_t_piece_lst(t_filler_piece *piece, int x, int y)
{
	if (!piece)
	{
		if (!(piece = (t_filler_piece*)malloc(sizeof(t_filler_piece))))
			return (NULL);
		piece->x = x;
		piece->y = y;
		piece->prev = NULL;
		piece->prev = NULL;
		return (piece);
	}
	while (piece->next)
		piece = piece->next;
	if (!(piece->next = handle_t_piece_lst(piece->next, x, y)))
		return (NULL);
	piece->next->prev = piece;
	piece = piece->next;
	return (piece);
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
