/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:12:17 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/08 11:39:55 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#include <stdio.h>

int			main(void)
{
	int				fd;//TO DELL
	t_filler_raw	*raw;
	t_filler_var	v;

	if ((fd = open("trace", O_RDWR)) < 0)//TO DELL
		return (write(1, "fd error\n", 9));//TO DEL

	v.loop_nb = 0;
	if (!(determine_players_token(&v)))
		return (0);
	//while (1)
	//{
		init_and_reset_var(&v);
		if (!(raw = get_raw_standard_input_to_raw_lst()))
			return (0);
		if (!(extract_values_from_raw_lst_to_var_lst(&v, raw)))
			return (0);
		del_and_set_to_null_t_filler_raw(&raw);
		if (v.loop_nb == 2 && v.player_token == 'O' &&
			(!(find_if_1_player_game(&v))))
			v.enemy_token_to_chase = 'x';
		/*if (!(compute_and_give_answer(&v)))
			return (0);*/
	//}
	write(1, "X Y\n", ft_strlen("X Y\n"));
	//}
	return (0);
}
