/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:12:17 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 12:09:08 by jlereffa         ###   ########.fr       */
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

	v.loop_nb = -1;
	v.is_1_player_game = 0;
	if (!(determine_ai_token(&v)))
		return (0);
	while (1)
	{
		init_t_filler_var(&v);
		if (!(raw = get_raw_standard_input_to_raw_lst()))
			return (0);
		if (!(extract_values_from_raw_to_var(&v, raw)))
			return (0);
		determine_and_give_answer(&v);
		del_and_set_to_null_raw(&raw);
	}
	write(1, "X Y\n", ft_strlen("X Y\n"));
	//}
	return (0);
}
