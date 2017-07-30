/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:12:17 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/30 18:11:54 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#include <stdio.h>

static void	del_raw(t_filler_raw **raw)
{
	t_filler_raw	*tmp;

	while (*raw)
	{
		tmp = *raw;
		if ((*raw)->prev && (*raw)->next)
		{
			(*raw)->next->prev = (*raw)->prev;
			(*raw)->prev->next = (*raw)->next;
			*raw = (*raw)->prev;
		}
		else if ((*raw)->prev && !(*raw)->next)
		{
			(*raw)->prev->next = NULL;
			*raw = (*raw)->prev;
		}
		else if (!(*raw)->prev && (*raw)->next)
		{
			(*raw)->next->prev = NULL;
			*raw = (*raw)->next;
		}
		else
			*raw = NULL;
		free(tmp);
	}
}

static void	init_t_filler_var(t_filler_var *v)
{
	v->plateau = NULL;
	v->plateau_height = 0;
	v->plateau_lenght = 0;
	v->piece = NULL;
	v->piece_height = 0;
	v->piece_lenght = 0;
	v->t_piece = NULL;
	v->player_token = 0;
//	v->player_token_to_overwrite = 0;
	v->ennemy_token = 0;
	v->ennemy_token_to_overwrite = 0;
	V->is_1_player_game = 0;
}

int			main(void)
{
	int				fd;
	t_filler_raw	*raw;
	t_filler_var	v;

	if ((fd = open("trace", O_RDWR)) < 0)
		return (write(1, "fd error\n", 9));
	raw = get_raw_standard_input_to_raw_lst(fd);
	init_t_filler_var(&v);
	if (!(extract_values_from_raw_to_var(&v, raw)))
		return (0);
	del_raw(&raw);
	if (!(v.t_piece = fill_t_piece(v.piece, v.t_piece)))
		return (0);
	determine_ai_token(&v, v->plateau);
	return (0);
}
