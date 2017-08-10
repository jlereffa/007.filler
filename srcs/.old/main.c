/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:12:17 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/09 10:11:54 by jlereffa         ###   ########.fr       */
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
	while (1)
	{
		DEB
		init_and_reset_var(&v);
		DEB
		if (!(raw = get_raw_standard_input_to_raw_lst()))
			return (0);
		DEB
		if (!(extract_values_from_raw_lst_to_var_lst(&v, raw)))
			return (0);
		DEB
		del_and_set_to_null_t_filler_raw(&raw);
		DEB
		if (v.loop_nb == 2 && v.player_token == 'O' &&
			(!(find_if_1_player_game(&v))))
			v.enemy_token_to_chase = 'x';
		DEB
		if (!(compute_and_give_answer(&v)))
			return (0);
		DEB
		sleep(5);
	}
	//write(1, "X Y\n", ft_strlen("X Y\n"));
	//}
	return (0);
}
